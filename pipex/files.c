/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:31:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/19 21:16:26 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h" 

int ft_check_file(char **argv, t_pipex *pipex)
{
	int fd;
	
	if (pipex->here_doc == true)
	{
		return (0);
	}
	else if (access(argv[1], F_OK|R_OK) == 0)
	{
		pipex->file = (char *)malloc(ft_strlen(argv[1]) * sizeof(char) + 1);
		if (!pipex->file)
			return (1);
		pipex->file = ft_strdup(argv[1]);
		if (!pipex->file)
			return (1);
		pipex->in_fd = open(argv[1], O_RDONLY);
	}
	else
	{
		fd = open(".error_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
		close(fd);
		pipex->file = ft_strdup(".error_fd");
		pipex->in_fd = open(".error_fd", O_RDONLY);
		ft_file_error(argv[1]);
	}
	return (0);
}

	void ft_outfile(int argc, char **argv, t_pipex *pipex)
{
	if (pipex->here_doc == true)
		pipex->out_fd = open(argv[argc - 1], O_RDWR| O_CREAT | O_APPEND, 0644);
	else
		pipex->out_fd =	open(argv[argc - 1], O_RDWR | O_CREAT| O_TRUNC, 0644);
}

