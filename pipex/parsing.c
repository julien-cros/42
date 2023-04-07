/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:12:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 19:57:07 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_valid_args(int argc, char **argv, t_pipex *pipex)
{
	int i; // i pour savoir si je deplace tout pour here_doc ou non;

	i = 0;
	if (argc <= 5)
		return (ft_putstr_fd("to few arguments", 1), -1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = true;
		if (ft_here_doc(argv, pipex) < 0)
			return (-1);
		i = 1;
	}
		pipex->cmd1 = argv[3+i];
		pipex->cmd2 = argv[2+i];
		pipex->valid_file = 0;
		 	
	// else if (argv[2+i] == ft_strrchr(argv[2+i]))
	// {
	// 	if (argv[3+i] == ft_strrchr(argv[3+i], "usr/bin/sh"))
	// 		pipex->valid_cmds = 0;
	// 	else
	// 		pipex->valid_cmds = 1;
	// }
	// else if (argv[3+i] == ft_strrchr(argv[3+i], "usr/bin/sh"))
	// 	pipex->valid_cmds = 2;
	// if (argv[1] && pipex->here_doc == false) // je doit trouver comment je fait pour trouver si le ficheier existe ou non;
	// {
	// 	pipex->valid_file = 1;
		
	// }
	// return (0);
}
