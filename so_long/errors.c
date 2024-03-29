/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:57:50 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/24 11:42:03 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_invalid_map(void)
{
	ft_putstr_fd("Error: Invalid map.\n", 1);
}

void	ft_error(void)
{
	ft_putstr_fd("Error.\n", 1);
	exit(0);
}

void	ft_error_x(void)
{
	ft_putstr_fd("Error X11.", 1);
	exit(0);
}

int	just_mlx(t_data *data)
{
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
	ft_error();
	exit(0);
}
