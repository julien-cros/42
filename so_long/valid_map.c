/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:47:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 15:31:14 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map.h"

static char	**ft_get_plan(char **plan, int fd);

t_map *ft_valid_map(t_map *map, int fd)
{
	int i;
	char buffer;
	
	i = 0;
	if (read(fd, &buffer, 1) > 0)
		map->plan = ft_get_plan(map->plan, fd);
	else 
		printf("not ok\n");

	return (map);
}

static char	**ft_get_plan(char **plan, int fd)
{
	int		i;
	int		j;
	char	buffer;

	if (!plan)
		return (NULL);
	i = 0;
	j = 0;
	while (read(fd, &buffer, 1) && buffer != '\0')
	{
		plan[i][j] = buffer; 
		if (buffer == '\n')
			if (i++)
				j = 0;
	}
	return (plan);
}

//
// first line 
// first col
// last line
// one e
// one p
// int c