/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:49 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/12 17:21:38 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*add_next_line(int fd, char *line);
char	*clear_line( char *buffer);
char	*clean_buffer(char *buffer);
char	*free_line(char *line, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = add_next_line(fd, buffer);
	if (!buffer)
		return (NULL);
	if (!buffer[0])
		line = (NULL);
	else
	{
		line = clear_line(buffer);
		if (!line)
			return (NULL);
	}
	buffer = clean_buffer(buffer);
	return (line);
}

char	*add_next_line(int fd, char *line)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
	{
		line = (char *)malloc(1);
		line[0] = 0;
	}
	if (!buffer || !line)
		return (free(buffer), free(line), NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytes] = 0;
		line = free_line(line, buffer);
	}
	return (free(buffer), line);
}

char	*clear_line(char *buffer)
{
	int	pos_of_newline;

	if (ft_strchr(buffer, '\n'))
		pos_of_newline = (ft_strchr(buffer, '\n') - buffer + 1);
	else
		pos_of_newline = (ft_strlen(buffer));
	return (ft_strndup(buffer, pos_of_newline));
}

char	*clean_buffer(char *buffer)
{
	char	*tmp;
	int		pos_of_newline;

	if (!buffer[0] || ft_strchr(buffer, '\n') == NULL)
		return (free(buffer), NULL);
	if (ft_strchr(buffer, '\n'))
		pos_of_newline = (ft_strchr(buffer, '\n') - buffer + 1);
	else
		pos_of_newline = (ft_strlen(buffer) + 1);
	tmp = buffer;
	buffer = ft_strndup(buffer + pos_of_newline, ft_strlen(buffer));
	free(tmp);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*free_line(char *line, char *buffer)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, buffer);
	if (!line)
		return (NULL);
	free(tmp);
	return (line);
}

// int main()
// {
// 	int fd = open("./test", O_RDONLY);

// 	for (int i = 0; i < 30; i++)
// 	{
//  		char *tmp = get_next_line(fd);
//  		printf("%s", tmp);
// 		if (tmp)
//  			free(tmp);
// 	}
// }