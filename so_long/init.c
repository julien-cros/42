/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:02 by codespace         #+#    #+#             */
/*   Updated: 2023/05/24 11:38:33 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_init_data(t_data *data, t_map *map)
{
	data->position_x = 0;
	data->position_y = 0;
	data->i = map->start_col_pos;
	data->j = map->start_raw_pos;
	data->collectible = map->collectible;
	data->length = 0;
	data->row = 0;
	data->keycode = 0;
	data->player_x = map->start_col_pos;
	data->player_y = map->start_raw_pos;
	data->exit = 0;
	data->step = 1;
	data->map = NULL;
	if (ft_init_img_path(data) != 0)
		return (ft_clean(map), -1);
	if (ft_init_texture(data) != 0)
		return (ft_clean(map), ft_free_with_i(data->img_path, 5), -1);
	return (0);
}

int	ft_init_img_path(t_data *data)
{
	int	i;

	i = -1;
	data->img_path = malloc(sizeof(char *) * 5);
	if (!data->img_path)
		return (-1);
	data->img_path[0] = ft_strdup("./assets/wall.xpm");
	data->img_path[1] = ft_strdup("./assets/exit.xpm");
	data->img_path[2] = ft_strdup("./assets/collectible.xpm");
	data->img_path[3] = ft_strdup("./assets/player.xpm");
	data->img_path[4] = ft_strdup("./assets/ground.xpm");
	while (++i < 5)
	{
		if (!data->img_path[i])
		{
			i = -1;
			while (++i < 5)
				if (data->img_path[i])
					free(data->img_path[i]);
			return (free(data->img_path), -1);
		}
	}
	return (0);
}

int	ft_find_p(char **strs, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i][j])
	{
		if (strs[i][j] == 'P')
		{
			map->start_col_pos = i;
			map->start_raw_pos = j;
			return (0);
		}
		j++;
		if (strs[i][j] == '\n')
		{
			i++;
			j = 0;
		}
	}
	return (-1);
}
