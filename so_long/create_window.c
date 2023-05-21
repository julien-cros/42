/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:33 by codespace         #+#    #+#             */
/*   Updated: 2023/05/21 10:16:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
# include "mlx/mlx.h"

int	ft_on_render(t_data *data)
{
	if (data->win == NULL)
	{
		ft_close_mlx(data);
		// exit(-1);
		return (-1);
	}
	ft_init_map(data);
	if (ft_print_steps(data) == -1)
	{
		// ft_close_mlx(data);
		// exit(-1);
		return (ft_close_mlx(data), -1);
	}
	return (0);
}

void	ft_init_window(t_map *map)
{
	t_data	*data;
	
	data = malloc(sizeof(t_data));
	if (!data)
		return ;
	if (ft_init_data(data, map) != 0)
		return ;
	if ( ft_init_data(data, map) !=0 ||ft_init_texture(data) != 0)
	{
		printf("ft_init_window1\n");
		// ft_close_mlx(data);
		// exit(-1);
		return (ft_error());
	}
	printf("ft_init_window2\n");
	data->win = mlx_new_window(data->mlx_ptr, 94 * map->length,  94 * map->row, "so_long");
	data->map = ft_create_2d(map);
	if (!data->win || !data->map)
	{
		// ft_close_mlx(data);
		// exit(-1);
		return (ft_error());
	}
	while (data->collectible > 0)
	{
		ft_init_map(data);
		mlx_hook(data->win, KeyRelease, KeyReleaseMask, &ft_check_move, data);
		mlx_loop(data->mlx_ptr);
	}
	
	// peut etre return ici avec close_mlx
	ft_close_mlx(data);
	return ;
}


int	ft_print_steps(t_data *data)
{
	char	*str;

	str = ft_itoa(data->step);
	if (!str)
		return (-1);
	mlx_string_put(data->mlx_ptr, data->win, 50, 50, 0x00FFFFFF, "Steps: ");
	mlx_string_put(data->mlx_ptr, data->win, 140, 50, 0x00FFFFFF, str);
	free(str);
	return (0);
}


// juste essayer de break;
// exit(0); au lieu de ft_close_mlx et je ft_close_mlx()apres;x