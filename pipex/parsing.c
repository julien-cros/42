/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:12:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:25:32 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	**ft_create_paths(char **envp);

int	ft_check_heredoc(char **argv, t_pipex *pipex)
{
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = true;
		if (ft_here_doc(argv, pipex) < 0)
			return (-1);
	}
	return (0);
}

int	ft_parse_cmds(int argc, char **argv, t_pipex *pipex)
{

	i = -1;
	j = 1;
	if (pipex->here_doc == true)
		j++;
	pipex->cmds = malloc(sizeof(char **) * (argc - j));
	if (!pipex->cmds)
		return (1);
	while (++j < argc - 1)
	{
		cmds = ft_split(argv[j], ' ');
		if (!cmds)
			return (ft_free_2d_with_i(pipex->cmds, -1), 1);
		pipex->cmds[++i] = cmds;
		pipex->cmds_count++;
	}
	pipex->out_name = ft_strdup(argv[argc - 1]);
	if (!pipex->out_name)
		return (1);
	return (0);
}

char	*ft_path_cmds(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*path;
	char	*temp;

	paths = ft_create_paths(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (ft_free_with_i(paths, -1), NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			return (ft_free_with_i(paths, -1), NULL);
		if (access(path, F_OK) == 0)
			return (ft_free_with_i(paths, -1), path);
		free(path);
	}
	return (ft_free_with_i(paths, -1), ft_cmds_error(cmd), NULL);
}

static char	**ft_create_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	return (paths);
}
