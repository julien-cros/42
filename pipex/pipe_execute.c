/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:12:07 by juliencros        #+#    #+#             */
/*   Updated: 2023/12/08 10:09:07 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipe_execute.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "parsing.h"
#include "files.h"
#include "error.h"

int	ft_setup(int fd[2], pid_t *pid, t_pipex *pipex, int i);

int	ft_fork_and_pipe(int fd[2], pid_t *pid)
{
	if (pipe(fd) == -1)
		return (-1);
	*pid = fork();
	if (*pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}
	return (0);
}

int	ft_pipex(t_pipex *pipex, char **envp, int i)
{
	pid_t	pid;
	int		fd[2];

	if (ft_fork_and_pipe(fd, &pid))
		return (-1);
	if (ft_setup(fd, &pid, pipex, i))
		return (-1);
	if (pid == 0)
	{
		close(fd[1]);
		if (pipex->cmds_path[i] != NULL)
			execve(pipex->cmds_path[i], pipex->cmds[i], envp);
		close(fd[0]);
		ft_free_pipex(pipex);
		exit(0);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}

int	ft_setup(int fd[2], pid_t *pid, t_pipex *pipex, int i)
{
	if (*pid == 0)
	{
		if (i == 0)
		{
			if (dup2(pipex->in_fd, STDIN_FILENO) == -1)
				return (-1);
		}
		if (i == pipex->cmds_count - 1)
		{
			if (dup2(pipex->out_fd, STDOUT_FILENO) == -1)
				return (-1);
		}
		else
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				return (-1);
		}
	}
	else
	{
		if (dup2(fd[0], STDIN_FILENO) == -1)
			return (-1);
	}
	return (0);
}
