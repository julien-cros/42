/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/10 12:03:54 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "parsing.h"
#include "ft_check_file.h"
#include "error.h"

int main(int argc, char **argv)
{
	
	t_pipex *pipex;
	// int fd[2];

	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex-> valid_file = 0;
	pipex->here_doc = false;
	pipex->cmds = 0;
	pipex->cmds_count = 0;
	pipex->out_name = 0;
	if (ft_check_heredoc(argv, pipex) != 0)
		return (ft_free_pipex(pipex), 1);
	if (ft_parse_cmds(argc, argv, pipex) != 0)
		return (ft_free_pipex(pipex), 1);
	if (ft_check_file(argv, pipex) != 0)
		return (ft_free_pipex(pipex), 1);
	ft_cmds_error(pipex->cmds[0]);
	ft_file_error(pipex->file);
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