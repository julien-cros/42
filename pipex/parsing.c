/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:12:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/02 14:46:58 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static	char	**ft_create_paths(char **envp);
static	char	*ft_fill_path(char **paths, char *cmd, char *path);

int	ft_parse_cmds(int argc, char **argv, t_pipex *pipex)
{
	int		i;
	int		j;
	char	**cmds;

	i = -1;
	j = 1 + pipex->here_doc;
	pipex->cmds = malloc(sizeof(char **) * (argc - j));
	if (!pipex->cmds)
		return (-1);
	while (++j < argc - 1)
	{
		cmds = ft_split(argv[j], ' ');
		if (!cmds)
			return (ft_free_2d_with_i(pipex->cmds, -1), 1);
		pipex->cmds[++i] = cmds;
		pipex->cmds_count++;
	}
	return (0);
}

char	*ft_path_cmds(char *cmd, char **envp)
{
	char	**paths;
	char	*path;

	path = NULL;
	if (access(cmd, F_OK) == 0)
	{
		path = ft_strdup(cmd);
		if (!path)
			return (NULL);
		return (path);
	}
	paths = ft_create_paths(envp);
	if (!paths)
		return (NULL);
	path = ft_fill_path(paths, cmd, path);
	if (path)
		return (path);
	return (ft_cmds_error(cmd, 1), NULL);
}

static	char	**ft_create_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	if (!paths)
		return (NULL);
	return (paths);
}

static	char	*ft_fill_path(char **paths, char *cmd, char *path)
{
	char	*temp;
	int		i;

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
	return (ft_free_with_i(paths, -1), NULL);
}
