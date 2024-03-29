/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:10 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/23 19:22:42 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	ft_free_pipex(t_pipex *pipex)
{
	if (pipex->in_fd)
		close(pipex->in_fd);
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
	if (pipex->here_doc)
		unlink(".here_doc_fd");
	if (pipex->invalid_in)
		unlink(".error_fd");
	if (pipex->urandom == true)
		unlink(".urandom_fd");
	free(pipex);
}

void	ft_free_with_i(char **strs, int i)
{
	int	j;

	j = 0;
	if (i != -1)
	{
		while (j < i)
		{
			free(strs[j]);
			j++;
		}
	}
	else
	{
		while (strs[j])
		{
			free(strs[j]);
			j++;
		}
	}
	free(strs);
}

void	ft_free_2d_with_i(char ***strs, int i)
{
	int	j;

	j = -1;
	if (i != -1)
		while (++j < i)
			ft_free_with_i(strs[j], -1);
	else
		while (strs[++j])
			ft_free_with_i(strs[j], -1);
	free(strs);
}
