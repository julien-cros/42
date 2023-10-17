/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:14:22 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 12:39:42 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <unistd.h>

void	ft_init_data(t_data *data)
{
	data->in = dup(STDIN);
	data->out = dup(STDOUT);
	data->in_fd = -1;
	data->out_fd = -1;
	data->pipe_in = -1;
	data->pipe_out = -1;
	data->pid = -1;
	data->charge = 0;
	data->is_here_doc = false;
	data->is_executable = true;
	data->is_parent = false;
	data->is_builtin = false;
	data->last = 0;
	data->return_status = 0;
	data->exit = -1;
}

