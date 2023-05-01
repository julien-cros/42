/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:31:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 13:50:19 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h" 

int	ft_check_file(int argc, char **argv, t_pipex *pipex)
{	
	if (create_out_name(pipex, argc, argv) != 0)
		return (-1);
	if (pipex->here_doc == true)
		return (ft_outfile(argc, argv, pipex), 0);
	if (access(argv[1], F_OK) == -1)
	{
		pipex->invalid_in = true;
		pipex->in_fd = open(".error_fd", O_RDWR | O_CREAT | O_TRUNC, 0644);
		pipex->file = ft_strdup(".error_fd");
		ft_file_error(argv[1], 1);
	}
	else
	{
		pipex->in_fd = open(argv[1], O_RDONLY);
		pipex->file = ft_strdup(argv[1]);
		if (!pipex->file)
			return (1);
	}
	ft_outfile(argc, argv, pipex);
	return (0);
}

void	ft_outfile(int argc, char **argv, t_pipex *pipex)
{
	if (pipex->here_doc == true)
		pipex->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		pipex->out_fd = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
}

int create_out_name(t_pipex *pipex, int argc, char **argv)
{
	pipex->out_name = ft_strdup(argv[argc - 1]);
	if (!pipex->out_name)
		return (-1);
	return (0);
}
