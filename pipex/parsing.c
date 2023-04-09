/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:12:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/09 17:34:35 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_check_heredoc(char **argv, t_pipex *pipex)
{		
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = true;
		if (ft_here_doc(argv, pipex) < 0)
			return (-1);
	}
	return (0);
}	

int ft_parse_cmds(int argc, char **argv, t_pipex *pipex)
{
	int j;
	int i;

	j = 2;
	i = 0;
	printf("in parse\n");
	if (pipex->here_doc == true)
		j++;
	pipex->cmds = (char **)malloc((argc - j) * sizeof(char *));
	while (j < argc - 1)
	{
		
		printf("la\n");
		pipex->cmds[i] = (char *)malloc(ft_strlen(argv[j]) * sizeof(char) + 1);
		if (!pipex->cmds[i])
			return (1);
		printf("ke sais pas ce qu'il se passe\n");
		pipex->cmds[i] = ft_strdup(argv[j]);
		printf("pas la\n");
		j++;
		i++;
		pipex->cmds_count += 1;
		printf("in while parse_cmds\n");
	}
	pipex->out_name = (char *)malloc(ft_strlen(argv[j]) * sizeof(char));
	if (!pipex->out_name)
		return (1);
	pipex->out_name = ft_strdup(argv[j]);
	return (0);
}


// int ft_check_file(char **argv, t_pipex *pipex)
// {
	
// }


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

