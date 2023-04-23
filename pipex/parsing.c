/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:12:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/23 14:36:34 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
	int		i;
	int		j;
	char	**cmds;

	i = 0;
	j = 2;
	if (pipex->here_doc == true)
		j++;
	pipex->cmds = malloc(sizeof(char **) * (argc - j));
	if (!pipex->cmds)
		return (1);
	while (j < argc - 1)
	{
		cmds = ft_split(argv[j], ' ');
		if (!cmds)
			return (ft_free_2d_with_i(pipex->cmds, j), 1);
		pipex->cmds[i] = cmds;
		pipex->cmds_count++;
		i++;
		j++;
	}
	pipex->out_name = ft_strdup(argv[j]);
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

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i], ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return(ft_free_with_i(paths, -1), NULL);
		path = ft_strjoin(temp, cmd);
		free(temp);
		if (!path)
			return (ft_free_with_i(paths, -1), NULL);
		if (access(path, F_OK) == 0)
		{
			ft_free_with_i(paths, -i);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_with_i(paths, -1);
	ft_cmds_error(cmd);
	return (NULL);
}

// int ft_cmds_path(t_pipex *pipex, char **envp)
// {
// 	int i;
// 	int j;
// 	char *path;
// 	char *tmp;
// 	char *tmp2;

// 	i = 0;
// 	j = 0;
// 	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
// 		i++;
// 	path = ft_strdup(envp[i] + 5);
// 	while (path[j] != '\0')
// 	{
// 		if (path[j] == ':')
// 			path[j] = '/';
// 		j++;
// 	}
// 	j = 0;
// 	while (pipex->cmds[j] != NULL)
// 	{
// 		tmp = ft_strjoin(path, "/");
// 		tmp2 = ft_strjoin(tmp, pipex->cmds[j][0]);
// 		pipex->cmds[j][0] = ft_strdup(tmp2);
// 		j++;
// 	}
// 	return (0);
// }

// char *ft_path_cmds(t_pipex *pipex, char **envp)
// {
// 	int i;
// 	int j;
// 	char *buffer;
// 	char **paths;

// 	i = 0;
// 	j = 0;
// 	printf("je suis la\n");
// 	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
// 		i++;
// 	paths = ft_split(envp[i] + 5, ':');
// 	if (!paths)
// 		return (1);
// 	while (buffer[i] != '\0')
// 	{
// 		if (buffer[i] == ':')
// 			buffer[i] = '/';
// 		i++;
// 	}
// 	printf("je suis aussi la\n");
// 	while (ft_strncmp(&envp[i][j], "/bin", 4) != 0)
// 			j++;
// 	printf("avant strjoin\n");
// 	buffer = ft_strjoin(buffer, "/bin");
// 	if (!buffer)
// 		return (1);
// 	printf("apres strjoin\n");
// 	i = 0;
// 	j = 0;
// 	printf("encore moi\n");
// 	buffer = ft_strjoin(buffer, *pipex->cmds[i]);
// 	if (!buffer)
// 		return (1);
// 	if (access(buffer, F_OK) > 0)
// 		printf("vat is in it\n");
// 	else
// 		printf("it's not working\n");
// 	return (0);
// }

// acess to find the path of the command