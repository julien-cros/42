/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:30:02 by codespace         #+#    #+#             */
/*   Updated: 2023/05/15 13:30:31 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void ft_init_data(t_data *data, t_map *map)
{
	data->img_path = malloc(sizeof(char *) * 5);
	data->img_path[0] = ft_strdup("./assets/wall.xpm");
	data->img_path[1] = ft_strdup("./assets/exit.xpm");
	data->img_path[2] = ft_strdup("./assets/collectible.xpm");
	data->img_path[3] = ft_strdup("./assets/player.xpm");
	data->img_path[4] = ft_strdup("./assets/ground.xpm");
	data->position_x = 0;
	data->position_y = 0;
	data->i = 0;
	data->j = 0;
	data->length = 0;
	data->row = 0;
	data->keycode = 0;
	data->player_x = map->start_col_pos;
	data->player_y = map->start_raw_pos;
}
