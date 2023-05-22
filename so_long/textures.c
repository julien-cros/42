/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:29:01 by codespace         #+#    #+#             */
/*   Updated: 2023/05/22 19:12:33 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_init_texture(t_data *data)
{
	int	i;
	int	size;

	i = 0;
	while (i < 5)
	{
		data->img[i] = mlx_xpm_file_to_image
			(data->mlx_ptr, data->img_path[i], &size, &size);
		if (!data->img[i])
			return (-1);
		i++;
	}
	return (0);
}

void	ft_init_map(t_data *data)
{
	data->position_x = 0;
	data->position_y = 0;
	data->i = 0;
	data->j = 0;
	while (data->map[data->i][data->j] != '\0')
	{
		if (data->map[data->i][data->j] == '\n')
		{
			data->j = 0;
			data->i++;
			data->position_y += 94;
			data->position_x = 0;
		}
		else
		{
			ft_what_image(data);
			data->position_x += 94;
			data->j++;
		}
	}
}

void	ft_what_image(t_data *data)
{
	if (data->map[data->i][data->j] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win,
			data->img[0], data->position_x, data->position_y);
	if (data->map[data->i][data->j] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win,
			data->img[1], data->position_x, data->position_y);
	if (data->map[data->i][data->j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win,
			data->img[2], data->position_x, data->position_y);
	if (data->map[data->i][data->j] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win,
			data->img[3], data->position_x, data->position_y);
	if (data->map[data->i][data->j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win,
			data->img[4], data->position_x, data->position_y);
}
