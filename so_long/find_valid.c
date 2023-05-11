/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 20:24:23 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/11 13:29:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_find_if_possible(t_map *map)
{
	int collectible_count;
	collectible_count = 0;
	if (ft_find_p(map->strs, map) != 0)
		return (-1);
	map->i = map->start_col_pos;
	map->j = map->start_raw_pos;
	printf("ok");
	while (map->collectible != collectible_count || map->is_valid != true)
	{
		if ((map->collectible == collectible_count) && (map->is_valid == true))
			return (0);
		if (ft_find_character(map, 'E') == 0)
		{
			ft_change_position(map, 'E', 1);
			map->is_valid = true;
		}
		if (ft_find_character(map, 'C') == 0)
		{
			ft_change_position(map, 'C', 1);
			collectible_count += 1;
		}
		if (ft_change_position(map, '0', 1) != 0)
			if (ft_go_back(map) != 0)
				return (printf("error.\n"), -1);
	}
	return (0);
}

int	ft_change_position(t_map *map, char c, int way)
{
	if (way > 0)
		map->strs[map->i][map->j] = map->index;
	if (way < 0)
		map->strs[map->i][map->j] = '1';
	if (map->strs[map->i][map->j+1] == c)
		map->j = map->j+1;
	else if (map->strs[map->i+1][map->j] == c)
		map->i = map->i+1;
	else if (map->strs[map->i-1][map->j] == c)
		map->i = map->i-1;
	else if (map->strs[map->i][map->j-1] == c)
		map->j = map->j-1;
	else
		return (-1);
	map->index += way;
	if (map->index == 'z' + 1)
		map->index = 'a';
	if (map->index == 'a' - 1)
		map->index = 'z';
	return (0);
}

int ft_go_back(t_map *map)
{
	if (ft_change_position(map, map->index-1, -1) == 0) 
		return (0);
	else if (map->index == 'a' && ft_find_character(map, 'z') == 0)
	{
		ft_change_position(map, 'z', -1);
		map->index = 'z';
	}
	if (ft_change_position(map, '0', 1) != 0 && map->i == map->start_col_pos && map->j == map->start_raw_pos)
		return(-1);
	return (0);
}


int ft_find_character(t_map *map, char c)
{
	if (map->strs[map->i][map->j+1] == c)
		return (0);
	else if (map->strs[map->i+1][map->j] == c)
		return (0);
	else if (map->strs[map->i-1][map->j] == c)
		return (0);
	else if (map->strs[map->i][map->j-1] == c)
		return (0);
	else
		return (-1);
}

char **ft_create_2d(t_map *map)
{
	char **strs;
	int i;
	int indx;

	i = 0;
	indx = 0;
	strs = malloc((map->row + 1) * sizeof(char **));
	if (!strs)
		return (NULL);
	while (i < map->row)
	{
		strs[i] = ft_strndup(map->plan+indx ,map->length + 1);
		if (!strs)
			return (NULL);
		indx += map->length + 1;
		i++;
	}
	strs[i] = '\0';
	return(strs);
}