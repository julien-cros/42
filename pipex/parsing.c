/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:12:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/12 20:42:26 by juliencros       ###   ########.fr       */
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

// int ft_parse_cmds(int argc, char **argv, t_pipex *pipex)
// {
// 	int j;
// 	int i;

// 	j = 2;
// 	i = 0;
// 	if (pipex->here_doc == true)
// 		j++;
// 	// if (ft_check_spaces(argv) > 0)
// 		// i = ft_check_spaces(argv);
// 	// else 
// 	// 	i = 0;
// 	pipex->cmds = (char **)malloc((argc - j)+ i * sizeof(char *));
// 	while (j < argc - 1)
// 	{
// 		pipex->cmds[i] = (char *)malloc(ft_strlen(argv[j]) * sizeof(char) + 1);
// 		if (!pipex->cmds[i])
// 			return (1);
// 		// if (ft_strchr(argv[j], ' '))
// 		// 	ft_split(argv[j], ' ');
// 		pipex->cmds[i] = ft_strdup(argv[j]);
// 		j++;
// 		i++;
// 		pipex->cmds_count += 1;
// 	}
// 	pipex->out_name = (char *)malloc(ft_strlen(argv[j]) * sizeof(char));
// 	if (!pipex->out_name)
// 		return (1);
// 	pipex->out_name = ft_strdup(argv[j]);
// 	return (0);
// }

int ft_parse_cmds(int argc, char **argv, t_pipex *pipex)
{
	int i;
	int j;
	char **cmds;

	i = 0;
	j = 2;
	if (pipex->here_doc == true)
		j++;
	pipex->cmds = malloc((argc - j) * sizeof(char **));
	if (!pipex->cmds)
		return (1);	
	while (j < argc - 1)
	{
		cmds = ft_split(argv[j], ' ');
		if (!cmds)
			return (1);
		pipex->cmds[i] = cmds;
		i++;
		j++;
	}
	pipex->out_name = (char *)malloc(ft_strlen(argv[j])+ 1 * sizeof(char));
	if (!pipex->out_name)
		return (1);
	pipex->out_name = ft_strdup(argv[j]);
	return (0);
}



// int ft_check_spaces(char **argv)
// {
// 	int i;
// 	int j;
// 	int count;

// 	i = 0;
// 	j = 0;
// 	count = 0;
// 	while (argv[i])
// 	{
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] == ' ')
// 				count++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (count);
// }


// int ft_cmds_path(t_pipex *pipex)
// {
	
// }