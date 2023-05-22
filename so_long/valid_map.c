/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:47:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/22 19:45:00 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_valid_map(t_map *map)
{
	map->plan = ft_fill_map(map->fd);
	if (!map->plan)
		return (-1);
	if (ft_check_chars(map) != 0)
		return (-1);
	if (map->exit != 1 || map->spawn != 1 || map->collectible < 1)
		return (ft_invalid_map(), -1);
	if (ft_check_walls(map) != 0)
		return (-1);
	map->strs = ft_create_2d(map);
	if (!map->strs)
		return (-1);
	if (ft_find_if_possible(map) != 0)
		return (-1);
	return (0);
}

char	*ft_strjoinne(char *str, char c)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!str || !c)
		return (NULL);
	new = ft_calloc(sizeof(char), (ft_strlen(str) + 2));
	if (!new)
		return (NULL);
	while (i < ft_strlen(str))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[++i] = '\0';
	return (new);
}

int	ft_check_walls(t_map *map)
{
	int	i;
	int	indx;

	indx = 0;
	i = -1;
	while (map->plan[++i])
	{
		if (map->plan[i] == '\n')
		{
			if (map->plan[i - 1] != '1' || map->plan[i + 1] != '1')
				return (ft_invalid_map(), -1);
			indx++;
		}
		else if (indx == 0 || indx == map->row - 1)
		{
			if (map->plan[i] != '\n' && map->plan[i] != '\0')
			{
				if (map->plan[i] != '1')
					return (ft_invalid_map(), -1);
			}
		}
	}
	return (0);
}

// int	ft_check_chars(t_map *map)
// {
// 	int	i;
// 	int	line_size;

// 	i = 0;
// 	line_size = 0;
// 	while (map->plan[i])
// 	{
// 		if (map->plan[i] == '\n' && map->length == 0)
// 			map->length = i;
// 		if (map->plan[i] == '\n')
// 		{
// 			if (line_size != map->length)
// 				return (ft_invalid_map(), -1);
// 			map->row++;
// 			line_size = -1;
// 		}
// 		else if (map->plan[i] == 'P')
// 		{
// 			map->start_col_pos = map->row - 1;
// 			map->start_raw_pos = i - ((map->start_col_pos) * (map->length));
// 			map->spawn++;
// 		}
// 		else if (map->plan[i] == 'E')
// 			map->exit++;
// 		else if (map->plan[i] == 'C')
// 			map->collectible++;
// 		else if (map->plan[i] != '0' && map->plan[i] != '1')
// 			return (ft_invalid_map(), -1);
// 		i++;
// 		line_size++;
// 	}
// 	if (map->length == map->row)
// 		return (ft_invalid_map(), -1);
// 	return (0);
// }

int	ft_check_chars(t_map *map)
{
	int	i;

	i = -1;
	while (map->plan[++i])
	{
		if (map->plan[i] != '0' && map->plan[i] != '1'
			&& map->plan[i] != 'C' && map->plan[i] != 'E'
			&& map->plan[i] != 'P' && map->plan[i] != '\n')
			return (ft_invalid_map(), -1);
		if (map->plan[i] == 'P')
			map->start_col_pos = map->row - 1;
			map->start_raw_pos = i - ((map->start_col_pos) * (map->length));
			map->spawn++;
		if (map->plan[i] == 'E')
			map->exit++;
		if (map->plan[i] == 'C')
			map->collectible++;
	}
	if (ft_check_length(map) != 0)
		return (ft_invalid_map(), -1);
	return (0);
}

int	ft_check_length(t_map *map)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (map->plan[i])
	{
		if (map->plan[i] == '\n' && map->length == 0)
			map->length = i;
		if (map->plan[i] == '\n')
		{
			if (length != map->length)
				return (-1);
			map->row++;
			length = -1;
		}
		i++;
		length++;
	}
	if (map->length == map->row)
		return (-1);
}
