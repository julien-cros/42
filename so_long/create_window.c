/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:33 by codespace         #+#    #+#             */
/*   Updated: 2023/05/15 17:12:39 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
# include "mlx/mlx.h"

int ft_on_render(t_data *data)
{
	if (data->win == NULL)
		return (0);
	// ft_clear_window(data);
	ft_init_map(data);
	printf("on render\n");
	return (0);
}

void ft_init_window(t_map *map)
{
	t_data *data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	data->mlx_ptr = mlx_init();
	// if (!data->mlx_ptr)
		// return ;
	ft_init_data(data, map);
	ft_init_texture(data);
	data->win = mlx_new_window(data->mlx_ptr, 96 * map->length,  96 * map->row, "so_long");
	data->map = ft_create_2d(map);
	ft_init_map(data);
	data->i = map->start_col_pos;
	data->j = map->start_raw_pos;
	mlx_loop_hook(data->win, &ft_on_render, data);
	printf ("after loop hook\n");
	mlx_hook(data->win, KeyRelease, KeyReleaseMask, &ft_check_move, data);
	printf ("after key release\n");
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, ft_close, data);
	printf ("after destroy notify\n");
	mlx_loop(data->mlx_ptr);
}

// 	// mlx_hook(data->win, 2, 1L<<0, ft_key_hook, data);
// 	// mlx_hook(data->win, 17, 1L<<17, ft_close, data);
// 	// mlx_loop(data->mlx_ptr);
// }

// char	ft_read(int fd)
// {
// 	char buffer;
// 	char *valid_args;
	
// 	valid_args = "wasd";
// 	if (read(fd, &buffer, 0) > 0 && ft_strchr(valid_args, buffer) == 0)
// 		return (buffer);
// 	return (0);
// }

// int ft_strchr(char (*s), char c)
// {
// 	int i;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == c)
// 			return (1);
// 	}
// 	return (0);
// }