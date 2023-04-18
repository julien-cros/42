/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:12:07 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/17 21:45:01 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "parsing.h"
#include "files.h"
#include "error.h"

int ft_fork_and_pipe(int fd[2], pid_t *pid)
{
	if (pipe(fd) ==  -1)
		return (1);
	*pid = fork();
	if (*pid == -1)
	{
		printf("pas bon je crois\n");
		close(fd[0]);
		close(fd[1]);
		return(1);
	}
	return(0);	
}


int ft_pipex(t_pipex *pipex, char **envp, int i)
{
	// int fd[2];
	// pid_t pid;

	// if (ft_fork_and_pipe(fd, &pid))
	// 	return (1);
	// if (pid == 0)
	// {
	// 	if (i == 0)// if () premier argument in fd si il existe sinon error_fd
	// 	{
	// 		dup2(pipex->in_fd, STDIN_FILENO); 
	// 	}
	// 	else if (i == pipex->cmds_count - 1) // if () dernier argument creer out fd avec le nom donné
	// 	{
	// 		printf("in last cmd\n");
	// 		dup2(pipex->out_fd, STDOUT_FILENO);
	// 	}
	// 	else
	// 	{
	// 		dup2(fd[1], STDOUT_FILENO);
	// 	}
	// 	close(fd[0]);
	// 	if (!execve(pipex->cmds_path[i], pipex->cmds[i], envp))// je execve si je peux
	// 		ft_cmds_error(*pipex->cmds[i]);
	// }
	// else 
	// {
	// 	close(fd[1]);
	// 	dup2(fd[0], STDIN_FILENO);
	// 	waitpid(pid, NULL, 0);
	// }
	// return (0);
	// // else () 
	// // j'exit
	// // je close fd[0]
	// // je close fd[1]
	// // je sort et je re close et wait
	pid_t	pid;
	int		fd[2];

	if (!ft_fork_and_pipe(fd, &pid))
		return (1);
	if (pid == 0)
	{
		// printf("pid == 0\n");
		if (i == 0)
			dup2(pipex->in_fd, STDIN_FILENO);
		if (i == pipex->cmds_count - 1)
			dup2(pipex->out_fd, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		close(fd[0]); 
		if (execve(pipex->cmds_path[i], pipex->cmds[i], envp) == -1)
			ft_cmds_error(pipex->cmds[i][0]);
		exit(0);
	}
	else
	{
		// printf("else\n");
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
	// printf("je suis la\n");
	return (1);


} 



// while (i == cmd-count-1 ) creer out 
// crois que je l'ai toujours pas cree
