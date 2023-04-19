/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:10 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/19 23:04:07 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_free_pipex(t_pipex *pipex)
{
	int	i;

	i = -1;
	if (pipex->in_fd)
		close (pipex->in_fd);
	if (pipex->out_fd)
		close(pipex->out_fd);
	if (pipex->out_name)
		free(pipex->out_name);
	if (pipex->file)
		free(pipex->file);
	if (pipex->cmds)
		ft_free_3d(pipex->cmds);
	if (pipex->cmds_path)
		while (++i < pipex->cmds_count)
			free(pipex->cmds_path[i]);
	free(pipex);
}

void	ft_free_2d(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
}

void	ft_free_3d(char ***strs)
{
	int i;
	int j;

	i = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			free(strs[i][j]);
			j++;
		}
		i++;
	}
}
