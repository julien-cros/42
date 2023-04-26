/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:37 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/26 13:52:35 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"
#include <stdio.h>

static char	*ft_get_line(char *line);
static void	ft_print_heredoc(char *line, int fd);

static char	*ft_get_line(char *line)
{
	int		i;
	char	buffer;

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

static void	ft_print_heredoc(char *line, int fd)
{
	if (line)
		ft_putstr_fd(line, fd);
	write(1, "heredoc>", 9);
	// free(line);
}

int ft_here_doc(char **argv, t_pipex *pipex)
{
	char *buffer;

	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(1, "heredoc>", 9);
	// printf("buffer = %s\n", buffer);
	while (pipex->in_fd > 0)
	{
		printf("buufer = %s\n", buffer);
		if (buffer)
		{
			printf("je suis dnas if buffer\n");
			if ((ft_strncmp(argv[2], buffer, ft_strlen(argv[2])) == 0) 
				&& (ft_strlen(argv[2]) + 1 == ft_strlen(buffer)))
				break;
			else
				ft_print_heredoc(buffer, pipex->in_fd);
			free(buffer);
		}
		// printf("ok2\n");
		// if (buffer)
		// {
			// printf("buffer = %s\n", buffer);
			// ft_print_heredoc(buffer, pipex->in_fd);
		// }
		// printf("encore ok\n");
		// if (buffer)
			// free(buffer);
		// printf("j'en met partout\n");
		buffer = malloc(10000 * sizeof(char *));
		if (!buffer)
			return (-1);
		// printf("faut verifier\n");
		buffer = ft_get_line(buffer);
	}
	close(pipex->in_fd);
	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
	return (free(buffer), 0);
}
