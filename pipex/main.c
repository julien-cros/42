/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/24 13:47:41 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "parsing.h"
#include "files.h"
#include "error.h"
#include "pipe_execute.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;

	i = 0;
	if (argc < 5 || !envp)
		return (1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	ft_init(pipex);
	if (ft_check_heredoc(argv, pipex) != 0)
		return (ft_free_pipex(pipex), 1);
	if (ft_check_file(argv, pipex) != 0)
		return (ft_free_pipex(pipex), 1);
	ft_outfile(argc, argv, pipex);
	if (ft_parse_cmds(argc, argv, pipex) != 0)
		return (ft_free_pipex(pipex), 1);
	pipex->cmds_path = (char **)malloc(1 * sizeof(char *));
	if (!pipex->cmds_path)
		return(ft_free_pipex(pipex), 1);
	while (i < pipex->cmds_count)
	{
		pipex->cmds_path[i] = ft_path_cmds(*pipex->cmds[i], envp);
		if (!pipex->cmds_path)
			return (ft_free_pipex(pipex), 1);
		i++;
	}
	i = -1;
	while (++i < pipex->cmds_count)
		if (ft_pipex(pipex, envp, i) != 0)
			return (ft_free_pipex(pipex), 1);
	return (ft_free_pipex(pipex), 0);
}

///////////////////////////// apprendres les pipe

// 	int fd[2];
// 	if (pipe(fd) == -1)
// 	{
// 		return 1;
// 	}

// 	int pid1 = fork();
// 	if (pid1 < 0)
// 	{
// 		return 2;
// 	}
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		if (ft_strncmp())
// 	}

// 	int pid2 = fork();
// 	if (pid2 < 0)
// 	{
// 		return 3;
// 	}

// 	if (pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("wc", "wc", "-l", NULL);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);

// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);

//////////////////// ce que je doit faire

// char *args;
// args = "/bin/sh"
// par exemple lire un ficher , pipe donc ce que veux dire faire une autre commande et ecrire
// le resultat dans un nouveau fd
// <makefile cat | wc -l > out

// je cat dans un fd le makefile puis apres j'ecris dans un nouveau fd le resultat de la commande wc -l
// donc en gros j'ecris dans un nouveau fd ce que la commande retourne et j'ecris dans un nouveau fd ce que me retourne l'autre commande
// du fd de la premiere commande.

// ce que je doit ecrire:
// ./pipex makefile cat "wc -l" "out"