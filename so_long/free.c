/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:11:37 by codespace         #+#    #+#             */
/*   Updated: 2023/05/22 18:28:10 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_clean(t_map *map)
{
	if (map->fd != 0)
		close(map->fd);
	if (map->plan)
		free(map->plan);
	if (map->strs)
		ft_free_with_i(map->strs, -1);
	free(map);
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
	else if (i == -1)
	{
		while (strs[j])
		{
			free(strs[j]);
			j++;
		}
	}
	free(strs);
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

void	ft_free_img(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 5)
		if (data->img[i])
			mlx_destroy_image(data->mlx_ptr, data->img[i]);
}

int	ft_close_mlx(t_data *data)
{
	if (data->map)
		ft_free_with_i(data->map, -1);
	if (data->img_path)
		ft_free_with_i(data->img_path, 5);
	ft_free_img(data);
	ft_free_mlx(data);
	free(data);
	exit(0);
}
