/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:49 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/09 17:59:50 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*add_next_line(int fd, char *line);
char	*clear_line( char *buffer);
char	*clean_buffer(char *buffer);

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
	char	*tmp;
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line)
		line = (char *)malloc(1);
	if (!buffer || !line)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (free(line), free(buffer), NULL);
		buffer[bytes] = 0;
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
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

// int main()
// {
// 	int fd = open("./test", O_RDONLY);
//	
// 	for (int i = 0; i < 30; i++)
// 	{
// 		char *tmp = get_next_line(fd);
// 		printf("%s", tmp);
// 		if (tmp)
// 			free(tmp);
// 	}
// }