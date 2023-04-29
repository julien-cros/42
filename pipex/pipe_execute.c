/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:12:07 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 14:27:38 by jcros            ###   ########.fr       */
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

static void	ft_wait(int fd[2], pid_t pid);

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
	if (pid == 0)
	{
		if (i == 0)
			dup2(pipex->in_fd, STDIN_FILENO);
		if (i == pipex->cmds_count - 1)
			dup2(pipex->out_fd, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		if (pipex->cmds_path[i])
			execve(pipex->cmds_path[i], pipex->cmds[i], envp);
		else
		{
			close (pipex->in_fd);
			close (pipex->out_fd);
		}
		close(fd[1]);
		exit(0);
	}
	ft_wait(fd, pid);
	return (0);
}

static void	ft_wait(int fd[2], pid_t pid)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}
