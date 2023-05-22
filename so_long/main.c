/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:43:06 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/22 19:06:55 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "struct.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		return (-1);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_clean(map), -1);
	ft_init(map);
	map->fd = (open(argv[1], O_RDONLY));
	if (map->fd == -1)
		return (ft_clean(map), -1);
	if (ft_valid_map(map) != 0)
		return (ft_clean(map), -1);
	if (!map)
		return (ft_clean(map), -1);
	ft_init_window(map);
	if (map)
		ft_clean(map);
	return (ft_error(), -1);
}

void	ft_init(t_map *map)
{
	map->collectible = 0;
	map->exit = 0;
	map->is_valid = false;
	map->length = 0;
	map->plan = NULL;
	map->spawn = 0;
	map->row = 1;
	map->start_col_pos = 0;
	map->start_raw_pos = 0;
	map->i = 0;
	map->j = 0;
	map->index = 97;
	map->strs = NULL;
	map->fd = 0;
}
