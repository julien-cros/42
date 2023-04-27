/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:43:06 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/24 10:51:55 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "valid_map.h"
#include <stdlib.h>

int main()
{
	t_map *map;
	int fd;

	fd = (open("map.ber", O_RDONLY));
	map = malloc(sizeof(t_map));
	if (!map)
		return (-1);
	map = ft_valid_map(map, fd);
	if (!map)
		return(-1);
	free(map);
}