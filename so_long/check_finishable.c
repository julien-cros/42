/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finishable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:23:32 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/10 19:42:29 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_finishable.h"


char	**ft_create_2d(t_map *map);
int		ft_find_exit(char **strs, t_map *map);
int ft_search_row(char **strs, t_map *map, char c);
int ft_search_col(char **strs, t_map *map, char c);
int ft_find_p(char **strs, t_map *map);
int ft_find_char(char **strs, t_map *map, char c);
int ft_search_z(char **strs, int i, int j);
int ft_get_back_i(char **strs, t_map *map);
int ft_get_back_j(char **strs, t_map *map);

int if_can(t_map *map)
{
	char **map_2d;
	int i;

	i = 0;
	map_2d = ft_create_2d(map);
	if (!map_2d)
		return (-1);
	while (i < map->row)
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

int	ft_find_exit(char **strs, t_map *map)
{
	int collectible_count;
	
	collectible_count = 0;
	map->i = map->start_col_pos;
	map->j = map->start_raw_pos;
	map->index = 96;
	printf("strs[%d][%d] = %c\n", map->i, map->j, strs[map->i][map->j]);
	while(map->is_valid != true || map->collectible != collectible_count)
	{
		if (map->index == 'z')
			map->index = 'a';
		if (ft_find_char(strs, map, 'E') == 0)
		{
			printf("in e\n");
			map->is_valid = true;
		}
		if (ft_find_char(strs, map, 'C') == 0)
		{
			strs[map->i][map->j] = map->index++;
			if (ft_search_row(strs, map, 'C') != -1)
				map->j = ft_search_row(strs, map, 'C');
			if (ft_search_col(strs, map, 'C') != -1)
				map->i = ft_search_col(strs, map, 'C');
			collectible_count++;
		}
		if (ft_search_row(strs, map, '0') != -1)
		{
			strs[map->i][map->j] = map->index++;
			map->j = ft_search_row(strs, map, '0');
		}
		else if (ft_search_col(strs, map, '0') != -1)
		{
			strs[map->i][map->j] = map->index++;
			map->i = ft_search_col(strs, map, '0');
		}
		else
		{
			if (ft_get_back_j(strs, map) != -1)
			{
				printf ("j\n");
					strs[map->i][map->j] = '\0';
					map->j = ft_get_back_j(strs, map);
					map->index--;
			}
			else if (ft_get_back_i(strs, map) != -1)
			{
				printf ("i\n");
					map->i = ft_get_back_i(strs, map);
					strs[map->i][map->j] = '\0';
					map->index--;
			}
			if (strs[map->i][map->j] == 'a' && ft_find_char(strs, map, 'z'))
			{
				strs[map->i][map->j] = '\0';
				if (ft_search_col(strs, map, 'z') != -1)
					map->i = ft_search_col(strs, map, 'z');
				if(ft_search_row(strs, map, 'z') != -1)
					map->j = ft_search_row(strs, map, 'z');
				map->index = 122;
			}
			else if (map->index == 97 && ft_search_col(strs, map, '0') == -1 && ft_search_row(strs, map, '0') == -1)
				return(ft_error_finding_exit(), -1);
			if (map->i == map->row && map->j == map->length && map->collectible == collectible_count && map->exit == true)
			{
				printf("all ok");
				return (0);
			}
		}
		printf("strs[%d][%d] = %c         index = %c\n", map->i, map->j, strs[map->i][map->j], map->index);
	}
	printf("map->collectible = %d\ncollectible_count = %d\n", map->collectible, collectible_count);
	if (collectible_count != map->collectible)
		return(ft_error_collectible(), -1);
	return (0);
}

int ft_search_row(char **strs, t_map *map, char c)
{
	if (strs[map->i][map->j+1] == c)
		return (map->j+1);
	else if (strs[map->i][map->j-1] == c)
		return (map->j-1);
	return (-1);
}

int ft_search_col(char **strs, t_map *map, char c)
{
	if (strs[map->i+1][map->j] == c)
		return (map->i+1);
	else if (strs[map->i-1][map->j] == c)
		return (map->i-1);
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


int ft_find_char(char **strs, t_map *map, char c)
{
	if (strs[map->i][map->j+1] == c)
		return (0);
	else if (strs[map->i+1][map->j] == c)
		return (0);
	else if (strs[map->i-1][map->j] == c)
		return (0);
	else if (strs[map->i][map->j-1] == c)
		return (0);
	else
		return (-1);
}

// int ft_search_z(char **strs, t_map)
// {
// 	if (strs[i][j+1] == 122)
// 		return (0);
// 	else if (strs[i+1][j] == 122)
// 		return (0);
// 	else if (strs[i-1][j] == 122)
// 		return (0);
// 	else if (strs[i][j-1] == 122)
// 		return (0);
// 	else
// 		return (-1);
// }


int ft_get_back_j(char **strs, t_map *map)
{
	if (strs[map->i][map->j-1] == map->index - 1)
		return (map->j-1);
	else if (strs[map->i][map->j+1] == map->index - 1)
		return (map->j+1);
	return(-1);
}

int ft_get_back_i(char **strs, t_map *map)
{
	if (strs[map->i-1][map->j] == map->index - 1)
		return (map->i-1);
	else if (strs[map->i+1][map->j] == map->index - 1)
		return (map->i+1);
	return(-1);

}

// non je doir peut etre juste faire un booleen et continuer justqu a avoir tout les parametres
// if (map->finishable == true && map->collectible == collectible_count)
//	return (0);

// comment copier le chemin vers la sortie

// creer copie de P vers E et ensuite reculer pour trouver tout les C



// pour la fin si arrive au point de depart et que j'ai pas exit ou que j'ai pas count return pas bon