/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/02 14:42:53 by jcros            ###   ########.fr       */
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

static int	ft_first_check(int argc, char **argv, char **envp);
static int	ft_create_path(t_pipex *pipex, char **envp);

t_pipex	*ft_init(t_pipex *pipex)
{
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->here_doc = false;
	pipex->invalid_in = false;
	pipex->urandom = false;
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->valid_file = 0;
	pipex->cmds_count = 0;
	pipex->out_name = NULL;
	pipex->file = NULL;
	pipex->cmds = NULL;
	pipex->cmds_path = NULL;
	return (pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	int		i;

	i = -1;
	if (ft_first_check(argc, argv, envp) == -1)
		return (0);
	pipex = NULL;
	pipex = ft_init(pipex);
	if (!pipex)
		return (-1);
	if ((ft_check_file(argv, pipex) != 0)
		|| (ft_init_out(argc, argv, pipex) != 0)
		|| (ft_parse_cmds(argc, argv, pipex) != 0))
		return (ft_free_pipex(pipex), 1);
	if (ft_create_path(pipex, envp) != 0)
		return (ft_free_pipex(pipex), -1);
	while (++i < pipex->cmds_count)
		if (ft_pipex(pipex, envp, i) != 0)
			return (ft_free_pipex(pipex), -1);
	i = -1;
	while (++i < pipex->cmds_count)
		wait (NULL);
	return (ft_free_pipex(pipex), 0);
}

static int	ft_create_path(t_pipex *pipex, char **envp)
{
	int	i;

	i = -1;
	pipex->cmds_path = malloc(pipex->cmds_count * sizeof(char *));
	if (!pipex->cmds_path)
		return (-1);
	while (++i < pipex->cmds_count)
	{
		pipex->cmds_path[i] = ft_path_cmds(*pipex->cmds[i], envp);
		if (!pipex->cmds_path)
			return (-1);
	}
	return (0);
}

static int	ft_first_check(int argc, char **argv, char **envp)
{
	int	i;

	i = 0;
	if (!envp || argc < 5)
		return (-1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		i++;
	if (argc - i < 5)
		return (-1);
	else
		return (0);
}
