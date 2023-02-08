/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:49 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/08 18:54:14 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char *add_next_line(int fd, char *line);
// char *print_next_line(char *line);
// char *clear_line(char *line);
// char *cut_line(char *line);

// char	*get_next_line(int fd)
// {
// 	static char *new;
// 	char *line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line = add_next_line(fd, new);
// 	if (!line)
// 		return (NULL);
// 	if (ft_strlen(line) == 0)
// 		return (0);
// 		new = clear_line(line);
// 	if (!new)
// 		return (NULL);
// 	line = cut_line(line);
// 	if (!line)
// 		return (NULL);
// 	// if (!line[0] || ft_strchr(line, '\n') == NULL)
// 	// {
// 	// 	free(line);
// 	// 	return NULL;
// 	// }
// 	return (line);
// }

// char *add_next_line(int fd, char *line)
// {
// 	char *buffer;
// 	int bytes;
// 	char *prev;

// 	bytes = 1;
// 	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!line)
// 		line = (char *)malloc(1);
// 	if (!buffer || !line)
// 		return (NULL);
// 	while (!ft_strchr(line, '\n') && bytes > 0)
// 	{
// 		bytes = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes == -1 || !line)
// 		{
// 			free(buffer);
// 			return (NULL);
// 		}
// 		prev = line;
// 		buffer[bytes] = 0;
// 		line = ft_strjoin(line, buffer);
// 		if (!line)
// 			return (NULL);
// 		free(prev);
// 	}
// 	// if (ft_strchr(line, '\n'))
// 	// 		line[ft_strlen(line)] = '\0';
// 	free(buffer);
// 	return (line);
// }

// char *clear_line(char *line)
// {
// 	int pos_of_newline;
	
// 	// if (!line[0] || ft_strchr(line, '\n') == NULL)
// 	// {
// 	// 	free(line);
// 	// 	return NULL;
// 	// }
// 	if (ft_strchr(line, '\n'))
// 		pos_of_newline = (ft_strchr(line, '\n')+ 1) - line;
// 	else
// 		pos_of_newline = ft_strlen(line) + 1;
// 	return (ft_strndup(line + pos_of_newline, ft_strlen(line)));
// }

// char *cut_line(char *line)
// {
// 	char *tmp;
// 	int pos_of_newline;
	
// 	if (ft_strchr(line, '\n'))
// 		pos_of_newline = (ft_strchr(line, '\n')+ 1) - line;
// 	else
// 		pos_of_newline = ft_strlen(line);
// 	tmp = line;
// 	line = ft_strndup(line, pos_of_newline);
// 	free(tmp);
// 	return (line);
// }

// // int main()
// // {
// // 	int fd = open("./test", O_RDONLY);
	
// // 	for (int i = 0; i < 30; i++)
// // 	{
// // 		char *tmp = get_next_line(fd);
// // 		printf("%s", tmp);
// // 		if (tmp)
// // 			free(tmp);
// // 	}
// // }


char	*get_next_line(int fd);
char	*add_next_line(int fd, char *line);
char	*clear_line( char *buffer);
char	*clean_buffer(char *buffer);



char	*get_next_line(int fd)
{	
	// static char *buffer;
	// char *line;
	
	// if (fd < 0 || BUFFER_SIZE <= 0)
	// 	return (NULL);
	// buffer = add_next_line(fd, buffer);
	// if (!buffer[0])
	// 	line = (NULL);
	// else 
	// {
	// 	line = clear_line(buffer);
	// 	if (!line)
	// 		return (NULL);
	// }
	// buffer = clean_buffer(buffer);
	// return (line);
	static char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = add_next_line(fd, buffer);
	if (!buffer[0])
		line = NULL;
	else
		line = clear_line(buffer);

	buffer = clean_buffer(buffer);

	return (line);
}

char	*add_next_line(int fd, char *line)
{
	char *buffer;
	char *tmp;
	int bytes;
	
	if (!line)
		line = (char *)malloc(1);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || !line)
		return (NULL);
	bytes = 1;
	while(bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == - 1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = 0;
		tmp = line;
		line = ft_strjoin(line, buffer);
		free(tmp);
		if (!line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (line);
}

 char *clear_line( char *buffer)
{
	int pos_of_newline;

	if (ft_strchr(buffer, '\n'))
		pos_of_newline = (ft_strchr(buffer, '\n') - buffer + 1);
	else
		pos_of_newline = (ft_strlen(buffer));
	return (ft_strndup(buffer, pos_of_newline));
}

char *clean_buffer(char *buffer)
{
	char *tmp;
	int pos_of_newline;
	
	if (!buffer[0] || ft_strchr(buffer, '\n') == NULL)
	{
		free(buffer);
		return NULL;
	}
	if (ft_strchr(buffer, '\n'))
		pos_of_newline = (ft_strchr(buffer, '\n') - buffer + 1);
	else
		pos_of_newline = (ft_strlen(buffer) + 1);	
	tmp = buffer;
	buffer = ft_strndup(buffer + pos_of_newline , ft_strlen(buffer));
	free(tmp);
	if (!buffer)
		return (NULL);
	return (buffer);
}


// int main()
// {
// 	int fd = open("./test", O_RDONLY);
	
// 	for (int i = 0; i < 30; i++)
// 	{
// 		char *tmp = get_next_line(fd);
// 		printf("%s", tmp);
// 		if (tmp)
// 			free(tmp);
// 	}
// }
