/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:47:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/03 20:27:37 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map.h"

char *ft_fill_map(int fd);
char *ft_strjoinne(char *str, char c);
int ft_check_chars(t_map *map);

int ft_valid_map(t_map *map, int fd)
{
	
	map->plan = ft_fill_map(fd);
	if (!map->plan)
		return(-1);
	// printf("map->plan =\n%s\n", map->plan);
	if (ft_check_chars(map) != 0)
		return (-1);
	if (ft_check_walls(map) != 0)
		return (-1);
	printf ("ok!\n");
	return (0);
}

char *ft_fill_map(int fd)
{
	int		i;
	char	buffer;
	char	*temp;
	char	*line;
	i = 0;
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	while (read(fd, &buffer, 1) > 0 && buffer != '\0')
	{
		temp = line;
		line = ft_strjoinne(line, buffer);
		free(temp);
		if (!line)
			return(NULL);
		i++;
	}
	return (line);
}


char *ft_strjoinne(char *str, char c)
{
	char	*new;
	size_t	i;

	i = -1;
	if (!str | !c)
		return (NULL);
	new = malloc(ft_strlen(str) + 2 * sizeof(char));
	if (!new)
		return (NULL);
	while (++i < ft_strlen(str))
	{
		new[i] = str[i];
	}
	new[i] = c;
	new[++i] = '\0';
	// printf("new = %s\n", new);
	return (new);
}

int ft_check_chars(t_map *map)
	{
		int i;
		int line_size;

		i = 0;
		line_size = 0;
		while(map->plan[i])
		{
			if (map->plan[i] == '\n' && map->length == 0)
			{
				map->length = i;
			}
			if (map->plan[i] == '\n')
			{
				// printf("line_size = %d\nmap->length = %d\n", line_size, map->length);
				if (line_size != map->length)
					return (error_lenght_line(),-1); // ft_error_length_line;
				map->width++;
				line_size = -1;
			}
			else if (map->plan[i] == 'P')
				map->spawn++;
			else if (map->plan[i] == 'E')
				map->exit++;
			else if (map->plan[i] == 'C')
				map->collectible++;
			else if (map->plan[i] != '0' && map->plan[i] != '1')
				return (error_wrong_character(map->plan[i]), -1); // ft_wrong_character(map->plan[i])
			i++;
			line_size++;
		}
		if (map->length == map->width)
			return (ft_error_square(),-1); // ft_error_square()
		return (0);
	}

	// int ft_check_walls(t_map *map)
	// {
		
	// }