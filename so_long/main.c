/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:43:06 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/04 11:58:24 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "valid_map.h"
#include <stdlib.h>

void	ft_init(t_map *map);

int main()
{
	t_map *map;
	int fd;
	fd = (open("map.ber", O_RDONLY));
	map = malloc(sizeof(t_map));
	if (!map)
		return (-1);
	ft_init(map);
	if (ft_valid_map(map, fd) != 0)
		return(-1);
	if (!map)
		return(-1);
	free(map);
}

void	ft_init(t_map *map)
{
	map->collectible = 0;
	map->exit = 0;
	map->finishable = false;
	map->length = 0;
	map->plan = NULL;
	map->spawn = 0;
	map->width = 1;
	map->start_col_pos = 0;
	map->start_raw_pos = 0;
}