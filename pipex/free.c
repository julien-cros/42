/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:10 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/10 20:58:03 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void ft_free_pipex(t_pipex *pipex)
{
	int i;

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
			free(pipex->cmds[i]);
			i++;
		}
	}
	free(pipex);
}