/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:15:06 by codespace         #+#    #+#             */
/*   Updated: 2023/05/17 14:00:06 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include <X11/keysym.h>

int ft_check_move(int keysym, t_data *data)
{
	char *str;

	str = ft_itoa(data->step++);
	if (!str)
		return (-1);
	if (keysym == XK_Escape)
	{
		free(str);
		return(ft_close_mlx(data), 0);
	}
	if (ft_move(keysym, data) == 0)
	{
		ft_putstr_fd("you moved ", 1);
		ft_putstr_fd(str, 1);
		ft_putstr_fd(" times.\n", 1);
	}
	ft_check_reachable(data);
	if (data->collectible == 0 && data->exit == 1)
	{
		ft_putstr_fd("you win\n", 1);
		free(str);
		ft_close_mlx(data);
	}
	if (ft_on_render(data) == -1)
		return (ft_close_mlx(data), -1);
	free(str);
	return (0);
}

int	ft_move(int keysym, t_data *data)
{
	if (keysym == XK_w && data->map[data->player_x-1][data->player_y] != '1')
	{
		ft_what_print(data);
		data->player_x--;
	}
	else if (keysym == XK_s && data->map[data->player_x+1][data->player_y] != '1')
	{
		ft_what_print(data);
		data->player_x++;
	}
	else if (keysym == XK_a && data->map[data->player_x][data->player_y-1] != '1')
	{
		ft_what_print(data);
		data->player_y--;
	}
	else if (keysym == XK_d && data->map[data->player_x][data->player_y+1] != '1')
	{
		ft_what_print(data);
		data->player_y++;
	}
	else
		return (-1);
	return (0);
}

void ft_check_reachable(t_data *data)
{
	if (data->map[data->player_x][data->player_y] == '0')
	{
		data->map[data->player_x][data->player_y] = 'P';
		data->exit = 0;
	}
	else if (data->map[data->player_x][data->player_y] == 'E')
		data->exit = 1;
	else if (data->map[data->player_x][data->player_y] == 'C')
	{
		data->exit = 0;
		data->map[data->player_x][data->player_y] = 'P';
		data->collectible--;
	}
}

void ft_what_print(t_data *data)
{
	if (data->map[data->player_x][data->player_y] == 'P')
		data->map[data->player_x][data->player_y] = '0';
	else if (data->map[data->player_x][data->player_y] == 'E')
		data->map[data->player_x][data->player_y] = 'E';
	else if (data->map[data->player_x][data->player_y] == 'C')
		data->map[data->player_x][data->player_y] = '0';
}
