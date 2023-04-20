/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:10 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/20 16:51:14 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void ft_free_path(char **strs);

void	ft_free_pipex(t_pipex *pipex)
{
	if (pipex->in_fd)
		close (pipex->in_fd);
	if (pipex->out_fd)
		close(pipex->out_fd);
	if (pipex->out_name)
		free(pipex->out_name);
	if (pipex->file)
		free(pipex->file);
	if (pipex->cmds)
			ft_free_2d_with_i(pipex->cmds, pipex->cmds_count);
	if (pipex->cmds_path)
		ft_free_with_i(pipex->cmds_path, pipex->cmds_count);
	free(pipex);
}

void	ft_free_2d(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
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
	free(strs);
}


void ft_free_with_i(char **strs, int i)
{
	int j;

	j = -1;
	if (i != -1)
		while (++j < i)
			free(strs[j]);
	else
		while (strs[++j])
			free(strs[j]);
	free(strs);
}

void ft_free_2d_with_i(char ***strs, int i)
{
	int j;

	j = 0;
	if (i != -1)
		while (++j < i)
			ft_free_with_i(strs[j], -1);
	else
		while (strs[++j])
			ft_free_with_i(strs[j], -1);
	free(strs);
}