/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:37 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/02 13:45:39 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"
#include <stdio.h>

static void	ft_print_heredoc(char *line, int fd);

// int	ft_check_heredoc(char **argv, t_pipex *pipex)
// {
// 	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
// 	{
// 		pipex->here_doc = true;
// 		if (ft_here_doc(argv, pipex) < 0)
// 			return (-1);
// 		pipex->file = ft_strdup(".here_doc_fd");
// 		if (!pipex->file)
// 			return (-1);
// 	}
// 	return (0);
// }

 static int ft_init_here_doc(t_pipex *pipex)
{
	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (!pipex->in_fd)
		return (-1);
	pipex->here_doc = true;
	pipex->file = ft_strdup(".here_doc_fd");
	if (!pipex->file)
		return (-1);
	write(1, "heredoc>", 9);
	return (0);
}

char	*ft_get_line(char *line, char limitter, int fd)
{
	int		i;
	char	buffer;

	i = 0;
	if (!line)
		return (NULL);
	while (read(fd, &buffer, 1) > 0 && buffer != limitter)
	{
		line[i] = buffer;
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

static void	ft_print_heredoc(char *line, int fd)
{
	if (line)
		ft_putstr_fd(line, fd);
	write(1, "heredoc>", 9);
}

int	ft_here_doc(char **argv, t_pipex *pipex)
{
	char	*buffer;

	if (ft_init_here_doc(pipex) != 0)
		return (-1);
	while (pipex->in_fd > 0)
	{
		buffer = ft_calloc(10000, sizeof(char *));
		if (!buffer)
			return (-1);
		if (ft_get_line(buffer, '\n', pipex->in_fd))
		{
			if ((ft_strncmp(argv[2], buffer, ft_strlen(argv[2])) == 0)
				&& (ft_strlen(argv[2]) + 1 == ft_strlen(buffer)))
			{
				free(buffer);
				break ;
			}
			else
				ft_print_heredoc(buffer, pipex->in_fd);
			free(buffer);
		}
	}
	close(pipex->in_fd);
	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
	return (0);
}
