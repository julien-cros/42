/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:06 by codespace         #+#    #+#             */
/*   Updated: 2023/05/15 17:15:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <X11/keysym.h>

// int    key_hook(t_data *data)
// {
// 	if (keycode == KEY_ESC)
// 		exit(0);
// 	else if (keycode == KEY_W)
// 		move_up(data);
// 	else if (keycode == KEY_S)
// 		move_down(data);
// 	else if (keycode == KEY_A)
// 		move_left(data);
// 	else if (keycode == KEY_D)
// 		move_right(data);
// 	return (0);
// }

int ft_check_move(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		ft_close(data);
	if (ft_move(keysym, data))
		ft_init_map(data);
	if (data->collectible == 0 && data->map[data->player_x][data->player_y] == 'E')
	{
		printf("You win\n");
		ft_close(data);
	}
	return (0);
}

int ft_move(int keysym, t_data *data)
{
	int i = 0;
	
	printf("keycode: %d\n", keysym);
	if (keysym == XK_Escape)
		ft_close(data);
	else if (keysym == XK_Up && data->map[data->player_x-1][data->player_y] != '1')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->player_x--;
	}
	else if (keysym == XK_Down && data->map[data->player_x+1][data->player_y] != '1')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->player_x++;
	}
	else if (keysym == XK_Left && data->map[data->player_x][data->player_y-1] != '1')
	{
		printf ("left\n");
		data->map[data->player_x][data->player_y] = '0';
		data->player_y--;
		printf("end left\n");
	}
	else if (keysym == XK_Right && data->map[data->player_x][data->player_y+1] != '1')
	{
		printf ("la cool\n");
		data->map[data->player_x][data->player_y] = '0';
		data->player_y++;
	}
	else
		return (printf ("pas cool\n"), -1);
	data->map[data->player_x][data->player_y] = 'P';
	while (data->map[i])
		printf("%s\n", data->map[i++]);
	// ft_init_map(data);
	return (printf ("la\n"), 0);
}



void	ft_free_mlx(t_data *data)
{
	if (data->mlx_ptr)
	{
		if (data->win)
			mlx_destroy_window(data->mlx_ptr, data->win);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}

void	ft_free_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (data->img[i])
			mlx_destroy_image(data->mlx_ptr, data->img[i]);
}

void	ft_free_data(t_data *data)
{
	free(data->map);
	free(data);
}

int	ft_close(t_data *data)
{
	ft_free_textures(data);
	ft_free_mlx(data);
	ft_free_data(data);
	exit(0);
	return (0);
}