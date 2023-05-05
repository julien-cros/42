/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finishable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:23:32 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/04 23:46:28 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_finishable.h"


char	**ft_create_2d(t_map *map);
int		ft_find_exit(char **strs, t_map *map);
int ft_search_e(char **strs, int i, int j);
int ft_search_row(char **strs, int i, int j);
int ft_search_col(char **strs, int i, int j);
int ft_find_p(char **strs, t_map *map);

int if_can(t_map *map)
{
	char **map_2d;
	int i;

	i = 0;
	map_2d = ft_create_2d(map);
	if (!map_2d)
		return (-1);
	while (i < map->width)
	{
		printf("%s == %d\n", map_2d[i], i);
		i++;
	}
	if (ft_find_p(map_2d, map) != 0)
		return (-1);
	if (ft_find_exit(map_2d, map) != 0)
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

int	ft_find_exit(char **strs, t_map *map)
{
	char index;
	int i;
	int j;
	i = map->start_col_pos;
	j = map->start_raw_pos;
	index = 97;
	printf("strs[%d][%d] = %c\n", i, j, strs[i][j]);
	while(strs[i][j] != 'E')
	{
		printf("strs[%d][%d] = %c\n", i, j, strs[i][j]);
		if (ft_search_e(strs, i, j) == 0)
			return(0);
		if (ft_search_row(strs, i, j) != -1)
		{
			
			strs[i][j] = index++;
			j = ft_search_row(strs, i, j);
		}
		else if (ft_search_col(strs, i, j) != -1)
		{
			strs[i][j] = index++;
			i = ft_search_col(strs, i, j);
		}
		else
		{
			if (strs[i][j-1] == index - 1)
			{
				strs[i][j] = '\0';
				j--;
				index--;
			}
			else if (strs[i-1][j] == index - 1)
			{
				strs[i][j] = '\0';
				i--;
				index--;
			}
			else if (strs[i][j+1] == index - 1)
			{
				strs[i][j] = '\0';
				j++;
				index--;
			}
			else if (strs[i+1][j] == index - 1)
			{
				strs[i][j] = '\0';
				i++;
				index--;
			}
			else if (index == 97 && ft_search_col(strs, i, j) == -1 && ft_search_row(strs, i, j) == -1)
				return(ft_error_finding_exit(), -1); 
			
		}
	}
	return (-1);
}


int ft_search_e(char **strs, int i, int j)
{
	if (strs[i][j+1] == 'E')
		return (0);
	else if (strs[i+1][j] == 'E')
		return (0);
	else if (strs[i-1][j] == 'E')
		return (0);
	else if (strs[i][j-1] == 'E')
		return (0);
	return (-1);
}

int ft_search_row(char **strs, int i, int j)
{
	if (strs[i][j+1] == '0')
		return (++j);
	else if (strs[i][j-1] == '0')
		return (++j);
	return (-1);
}

int ft_search_col(char **strs, int i, int j)
{
	if (strs[i+1][j] == '0')
		return (++i);
	else if (strs[i-1][j] == '0')
		return (++i);
	return (-1);
}

int ft_find_p(char **strs, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (strs[i][j])
	{
		if (strs[i][j] == 'P')
		{
			map->start_col_pos = i;
			map->start_raw_pos = j;
			return (0);
		}
		j++;
		if (strs[i][j] == '\n')
		{
			i++;
			j = 0;
		}
	}
	return (-1);
}


		// printf("1strs[%d][%d] = %c\n", i, j, strs[i][j]);
		// if (strs[i][j+1] == '0' || strs[i][j+1] == 'E')
		// {
		// 	strs[i][j] = index++;
		// 	j++;
		// }
		// else if (strs[i+1][j] == '0')
		// {
		// 	strs[i][j] = index++;
		// 	printf("3strs[%d][%d] = %c\n", i, j, strs[i][j]);
		// 	i++;
		// }
		// else if (strs[i-1][j] == '0')
		// {
		// 	strs[i][j] = index++;
		// 	printf("4strs[%d][%d] = %c\n", i, j, strs[i][j]);
		// 	i--;
		// }
		// else if (strs[i][j-1] == '0')
		// {
		// 	strs[i][j] = index++;
		// 	printf("5strs[%d][%d] = %c\n", i, j, strs[i][j]);
		// 	j--;
		// }