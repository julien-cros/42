/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:43:06 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/21 10:17:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "struct.h"

void	ft_init(t_map *map);
// int ft_init_mlx(t_data *data, t_map *map);

int main(int argc, char **argv)
{
	t_map *map;
	// t_data *data;
	int fd;

	if (argc != 2)
		return (-1);
	// data = NULL;
	fd = (open(argv[1], O_RDONLY));
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_clean(map), -1);
	ft_init(map);
	if (ft_valid_map(map, fd) != 0)
		return(ft_clean(map), -1);
	close(fd);
	if (!map)
		return(ft_clean(map), -1);
	// if (ft_init_mlx(data, map) != 0)
		// return(ft_clean(map), ft_close_mlx(data),-1);
	ft_init_window(map);
	return (ft_clean(map), 0);
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
}

// int ft_init_mlx(t_data *data, t_map *map)
// {
// 	data = malloc(sizeof(t_data));
// 	if (!data)
// 		return (-1);
// 	if (ft_init_data(data, map) != 0)
// 		return(-1);
// 	return (0);
// }