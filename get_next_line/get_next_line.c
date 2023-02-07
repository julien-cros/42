/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:49 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/06 21:17:36 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *add_next_line(int fd, char *line);
char *print_next_line(char *line);
char *clear_line(char *line, char *new);

char	*get_next_line(int fd)
{
	static char *new;
	char *line;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = (char *)malloc(1);
	if (!line)
		return (NULL);
	if (new)
	{
		line = ft_strjoin(line, new);
		free(new);
	}
	line = add_next_line(fd, line);
	if (!line)
		return (NULL);
	new = clear_line(line, new);
	if (!new)
		return (NULL);
	if (ft_strlen(line) == 0)
		return (0);
	if (ft_strchr(line, '\n'))
		line[ft_strchr(line, '\n') - line + 1] = 0;
	return (line);
}

char *add_next_line(int fd, char *line)
{
	char *buffer;
	int bytes;
	char *prev;

	bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	prev = (char *)malloc(1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(line, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || !line)
		{
			free(buffer);
			return (NULL);
		}
		prev = line;
		buffer[bytes] = 0;
		line = ft_strjoin(line, buffer);
		free(prev);
	}
	free(buffer);
	return (line);
}

char *clear_line(char *line, char *new)
{
	int pos_of_newline;
	int i;

	if (ft_strchr(line, '\n'))
		pos_of_newline = (ft_strchr(line, '\n')+ 1) - line;
	else
		pos_of_newline = ft_strlen(line) + 1;
	i = 0;
	new = malloc((ft_strlen(line) - pos_of_newline + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < ft_strlen(line) - pos_of_newline + 1)
	{
		new[i] = line[i + pos_of_newline];
		i++;
	}
	return (new);
}

int main()
{
	int fd = open("./test", O_RDONLY);
	
	for (int i = 0; i < 1; i++)
	{
		char *tmp = get_next_line(fd);
		printf("%s", tmp);
		if (tmp)
			free(tmp);
	}
}
