/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finishable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:23:32 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/04 17:03:26 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_finishable.h"


char **ft_create_2d(t_map *map);

int if_can(t_map *map)
{
	char **map_2d;

	map_2d = ft_create_2d(map);
	if (!map_2d)
		return (-1);
	return (0);
}

char **ft_create_2d(t_map *map)
{
	char **strs;
	int i;
	int indx;

	i = 0;
	indx = 0;
	strs = malloc((map->width + 1) * sizeof(char **));
	if (!strs)
		return (NULL);
	while (i < map->width)
	{
		strs[i] = ft_strndup(map->plan+indx ,map->length + 1);
		if (!strs)
			return (NULL);
		indx += map->length + 1;
		i++;
	}
	return(strs);
}

// ft_find_exit(t_map *map)
// {
// 	while()
// }
