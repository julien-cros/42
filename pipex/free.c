/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:10 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/13 17:38:15 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void ft_free_pipex(t_pipex *pipex)
{
	int i;
	int j;

	i = 0;
	if (pipex->in_fd)
		close (pipex->in_fd);
	if (pipex->out_fd)
		close(pipex->out_fd);
	if (pipex->out_name)
		free(pipex->out_name);
	if (pipex->file)
		free(pipex->file);
	if (pipex->cmds)
	{
		while (pipex->cmds[i])
		{
			j = 0;
			while (pipex->cmds[i][j])
			{
				free(pipex->cmds[i][j]);
				j++;
			}
			i++;
		}
	}
	free(pipex);
}

void ft_free_2(char **strs)
{
	int i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
}