/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:37 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/26 11:15:38 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"

static char	*ft_get_line(char *line);
static void	ft_print_heredoc(char *line, int fd);

// int	ft_here_doc(char **argv, t_pipex *pipex)
// {
// 	char	*line;

// 	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	line = malloc(10000 * sizeof(char));
// 	if (!line)
// 		return (-1);
// 	while ((ft_strlen(argv[2]) + 1 != ft_strlen(line))
// 		// && (pipex->in_fd > 0)
// 		&& (ft_strncmp(argv[2], line, ft_strlen(argv[2]) != 0)))
// 	{
// 		if (line)
// 			ft_print_heredoc(line, pipex->in_fd);
// 		line = malloc(10000 * sizeof(char));
// 		if (!line)
// 			return (-1);
// 		line = ft_get_line(line);
// 	}
// 	close(pipex->in_fd);
// 	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
// 	return (free(line), 0);
// }

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
}

// int ft_here_doc(char **argv, t_pipex *pipex)
// {
// 	char *buffer;
	
// 	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	write(1, "heredoc>", 9);
// 	while (pipex->in_fd > 0)
// 	{
// 		free(buffer);
// 		buffer = malloc(10000 * sizeof(char));
// 		if (!buffer)
// 			return (-1);
// 		ft_print_heredoc(buffer, pipex->in_fd);
// 		if ((ft_strlen(argv[2])+1 != ft_strlen(buffer))
// 	 		&& (ft_strncmp(argv[2], buffer, ft_strlen(argv[2]+1)) != 0))
// 				break ;
// 		buffer = ft_get_line(buffer);
// 	}
// 	close(pipex->in_fd);
// 	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
// 	return (0);
// }

// int ft_here_doc(char **argv, t_pipex *pipex)
// {
// 	char *buffer;

// 	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	write (1, "heredoc>", 9);
// 	while (pipex->in_fd > 0)
// 	{
// 		if (buffer)
// 		{
// 			if (ft_strlen(argv[2])+1 != ft_strlen(buffer)
// 	 			&& (ft_strncmp(argv[2], buffer, ft_strlen(argv[2]+1)) != 0))
// 					break;
// 			else
// 			{
// 				ft_print_heredoc(buffer, pipex->in_fd);
// 				free(buffer);
// 			}
// 		}
// 		buffer = malloc(10000 * sizeof(char));
// 		if (!buffer)
// 			return (-1);
// 		buffer = ft_get_line(buffer);
// 	}
// 	close(pipex->in_fd);
// 	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
// 	return (free(buffer), 0);
// }

int ft_here_doc(char **argv, t_pipex *pipex)
{
	char *buffer;

	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(1, "heredoc>", 9);
	while (pipex->in_fd > 0)
	{
		if ((buffer 
			&& strncmp(argv[2], buffer, ft_strlen(argv[2])) == 0) 
			&& (ft_strlen(argv[2]) + 1 == ft_strlen(buffer)))
			break;
		if (buffer)
			ft_print_heredoc(buffer, pipex->in_fd);
		if (buffer)
			free(buffer);
		buffer = calloc(10000, sizeof(char));
		if (!buffer)
			return (-1);
		buffer = ft_get_line(buffer);
	}
	close(pipex->in_fd);
	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
	return (free(buffer), 0);
}

// int	ft_here_doc(char **argv, t_pipex *pipex)
// {
// 	char	*buffer;
// 	char	*temp;

// 	buffer = malloc(10000 * sizeof(char));
// 	if (!buffer)
// 		return(-1);
// 	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
// 	while (ft_strlen(argv[2])+1 != ft_strlen(buffer)
// 	 	&& (ft_strncmp(argv[2], buffer, ft_strlen(argv[2]) != 0)))
// 	{
// 		ft_print_heredoc(buffer, pipex->in_fd);
// 		buffer = malloc(10000 * sizeof(char));
// 		if (!buffer)
// 			return(-1);
// 		temp = buffer;
// 		buffer = ft_get_line(buffer);
// 		free(temp);
// 		if (!buffer)
// 			return (-1);
// 	}
// 	close(pipex->in_fd);
// 	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
// 	return (free(buffer), 0);
//	}
