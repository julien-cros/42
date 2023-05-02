/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:31:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/02 14:49:24 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h" 

int	ft_init_out(int argc, char **argv, t_pipex *pipex)
{
	if (pipex->here_doc == true)
		pipex->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		pipex->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipex->out_name = ft_strdup(argv[argc - 1]);
	if (!pipex->out_name)
		return (-1);
	return (0);
}

int	ft_check_file(char **argv, t_pipex *pipex)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0
		&& ft_strlen(argv[1]) == 8)
		if (ft_here_doc(argv, pipex) != 0)
			return (-1);
	if (ft_strncmp(argv[1], "/dev/urandom", 12) == 0
		&& ft_strlen(argv[1]) == 12)
	{
		if (ft_urandom(pipex) != 0)
			return (-1);
	}
	else
	{
		if (access(argv[1], F_OK) == 0)
		{
			if (ft_create_valid_in(argv, pipex) != 0)
				return (-1);
		}
		else
		{
			if (ft_create_invalid_in(pipex) != 0)
				return (-1);
			ft_file_error(argv[1], 0);
		}
	}
	return (0);
}

int	ft_create_invalid_in(t_pipex *pipex)
{
	pipex->invalid_in = true;
	pipex->in_fd = open(".error_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
	pipex->file = ft_strdup(".error_fd");
	if (!pipex->file)
		return (-1);
	return (0);
}

int	ft_create_valid_in(char **argv, t_pipex *pipex)
{
	pipex->in_fd = open(argv[1], O_RDONLY);
	pipex->file = ft_strdup(argv[1]);
	if (!pipex->file)
		return (1);
	return (0);
}
