/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:13:37 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 11:23:16 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "here_doc.h"

static char	*ft_get_line(char *line);
static void	ft_print_heredoc(char *line, int fd);

int	ft_here_doc(char **argv, t_pipex *pipex)
{
	char	*line;

	line = 0;
	pipex->in_fd = open(".here_doc_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
	line = malloc(10000 * sizeof(char));
	if (!line)
		return (-1);
	while (pipex->in_fd > 0
		&& ft_strlen(argv[2])+1 != ft_strlen(line)
		&& (ft_strncmp(argv[2], line, ft_strlen(argv[2]) != 0)))
	{
		if (line)
			ft_print_heredoc(line, pipex->in_fd);
		line = malloc(10000 * sizeof(char));
		line = ft_get_line(line);
		if (!line)
			return (-1);
	}
	free(line);
	close(pipex->in_fd);
	pipex->in_fd = open(".here_doc_fd", O_RDONLY);
	return (0);
}

static char	*ft_get_line(char *line)
{
	int	i;
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
	free(line);
}
