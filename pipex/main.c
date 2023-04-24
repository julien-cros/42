/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/24 19:49:16 by juliencros       ###   ########.fr       */
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

	i = -1;
	if (argc < 5 || !envp)
		return (1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	ft_init(pipex);
	if ((ft_check_heredoc(argv, pipex) != 0) ||
		(ft_check_file(argc, argv, pipex) != 0) ||
		(ft_parse_cmds(argc, argv, pipex) != 0))
		return (ft_free_pipex(pipex), 1);
	pipex->cmds_path = (char **)malloc(1 * sizeof(char *));
	if (!pipex->cmds_path)
		return(ft_free_pipex(pipex), 1);
	while (++i < pipex->cmds_count)
	{
		pipex->cmds_path[i] = ft_path_cmds(*pipex->cmds[i], envp);
		if (!pipex->cmds_path)
			return (ft_free_pipex(pipex), 1);
	}
	i = -1;
	while (++i < pipex->cmds_count)
		if (ft_pipex(pipex, envp, i) != 0)
			return (ft_free_pipex(pipex), 1);
	return (ft_free_pipex(pipex), 0);
}
