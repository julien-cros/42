/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:37 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/13 14:27:21 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"

char *ft_get_line(char *line);

int ft_here_doc(char **argv, t_pipex *pipex)
{
	int fd;
	char *line;

	line = 0;
	fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
	line = malloc(10000 * sizeof(char));
	if (!line)
		return (-1);
	while (fd > 0 && (ft_strncmp(argv[2], line, ft_strlen(argv[2]) != 0)))
	{
		if (line)
			ft_putstr_fd(line, fd);
		write(1, "heredoc>", 9);
		if (line)
			free(line);
		line = malloc(10000 * sizeof(char));
		if (!line)
			return (-1);
		line = ft_get_line(line);
		if (!line)
			return (-1);
	}
	if (line)
		free(line);
	close(fd);
	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
	return (0);
}

char *ft_get_line(char *line)
{
	int i;
	char buffer;

	i = 0;
	if (!line)
		return (NULL);
	while (read(0, &buffer, 1) > 0 && buffer != '\n')
	{
		line[i] = buffer;
		i++;
	}
	line[i] = '\n';
	return (line);
}
