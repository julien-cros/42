/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 19:39:35 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/24 08:20:23 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/**
 * @brief The ft_fill_map function fills the map with the content of the file
 * and returns the map as a string. If the file is empty or if the file is not
 * a valid map, the function returns NULL.
 * 
 * @param fd
 * @return char*
 * 
*/
char	*ft_fill_map(int fd)
{
	int		i;
	char	buffer;
	char	*temp;
	char	*line;

	i = 0;
	line = ft_calloc(sizeof(char), 1);
	if (!line)
		return (NULL);
	while (read(fd, &buffer, 1) > 0 && buffer != '\0')
	{
		temp = line;
		line = ft_strjoinne(line, buffer);
		free(temp);
		if (!line)
			return (NULL);
		i++;
	}
	if (line[i - 1] == '\n')
		line[i - 1] = '\0';
	return (line);
}

char	**ft_create_2d(t_map *map)
{
	char	**strs;
	int		i;
	int		indx;

	i = 0;
	indx = 0;
	if (!map->plan || !map->length || !map->row)
		return (NULL);
	strs = malloc((map->row + 1) * sizeof(char **));
	if (!strs)
		return (NULL);
	while (i < map->row)
	{
		strs[i] = ft_strndup(map->plan + indx, map->length + 1);
		if (!strs[i])
			return (ft_free_with_i(strs, i-1), NULL);
		indx += map->length + 1;
		i++;
	}
	strs[i] = '\0';
	return (strs);
}
