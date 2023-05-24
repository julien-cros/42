/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:33 by codespace         #+#    #+#             */
/*   Updated: 2023/05/24 09:04:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "mlx/mlx.h"

int	ft_on_render(t_data *data)
{
	if (data->win == NULL)
	{
		exit(-1);
		ft_close_mlx(data);
	}
	ft_init_map(data);
	if (ft_print_steps(data) == -1)
	{
		ft_close_mlx(data);
		exit(-1);
	}
	return (0);
}

void	ft_init_window(t_map *map)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), ft_clean(map), ft_error_X11());
	if (ft_init_data(data, map) != 0)
		return (just_mlx(data), ft_error());
	data->win = mlx_new_window
		(data->mlx_ptr, 94 * map->length, 94 * map->row, "so_long");
	if (!data->win)
		return (ft_clean(map), ft_close_mlx(data), ft_error());
	data->map = ft_create_2d(map);
	if (!data->map)
		return (ft_clean(map), ft_close_mlx(data), ft_error());
	ft_clean(map);
	ft_init_map(data);
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &ft_check_move, data);
	mlx_hook
		(data->win, DestroyNotify, StructureNotifyMask, &ft_close_mlx, data);
	mlx_loop(data->mlx_ptr);
}

int	ft_print_steps(t_data *data)
{
	char	*str;

	str = ft_itoa(data->step - 1);
	if (!str)
		return (0);
	mlx_string_put(data->mlx_ptr, data->win, 50, 50, 0x00FFFFFF, "Steps: ");
	mlx_string_put(data->mlx_ptr, data->win, 140, 50, 0x00FFFFFF, str);
	free(str);
	return (0);
}
