/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:23:09 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/14 15:26:46 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

void	ft_close(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_reset_std(t_data *data)
{
	dup2(data->in, STDIN);
	dup2(data->out, STDOUT);
}

void	ft_close_fds(t_data *data)
{
	ft_close(data->in_fd);
	ft_close(data->out_fd);
	ft_close(data->pipe_in);
	ft_close(data->pipe_out);
}

void	ft_reset_fds(t_data *data)
{
	data->in_fd = -1;
	data->out_fd = -1;
	data->pipe_in = -1;
	data->pipe_out = -1;
	data->pid = -1;
}
