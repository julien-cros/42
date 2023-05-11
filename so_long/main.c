/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:43:06 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/11 14:58:46 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "struct.h"

void	ft_init(t_map *map);

int main(int argc, char **argv)
{
	t_map *map;
	int fd;
	if (argc != 2)
		return (-1);
	fd = (open(argv[1], O_RDONLY));
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_clean(map), -1);
	ft_init(map);
	if (ft_valid_map(map, fd) != 0)
		return(ft_clean(map), -1);
	if (!map)
		return(ft_clean(map), -1);
	ft_init_window();
	return ( 0);
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
	map->mlx = NULL;
	map->win = NULL;
}