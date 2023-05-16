/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:33 by codespace         #+#    #+#             */
/*   Updated: 2023/05/16 10:43:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
# include "mlx/mlx.h"

int ft_on_render(t_data *data)
{
	if (data->win == NULL)
		return (0);
	ft_init_map(data);
	ft_print_steps(data);
	return (0);
}

void ft_init_window(t_map *map)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	ft_init_data(data, map);
	ft_init_texture(data);
	data->win = mlx_new_window(data->mlx_ptr, 96 * map->length,  96 * map->row, "so_long");
	data->map = ft_create_2d(map);
	ft_init_map(data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &ft_check_move, data);
	mlx_loop(data->mlx_ptr);
}


int ft_print_steps(t_data *data)
{
	
}