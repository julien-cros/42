/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:21:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 10:25:34 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "env.h"
#include "mem.h"
#include "str.h"
#include "display.h"
#include "token.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

// int			error_message(char *path)
// {
// 	DIR	*folder;
// 	int	fd;
// 	int	ret;

// 	fd = open(path, O_WRONLY);
// 	folder = opendir(path);
// 	ft_putstr_fd("minishell: ", STDERR);
// 	ft_putstr_fd(path, STDERR);
// 	if (ft_strchr(path, '/') == NULL)
// 		ft_putstr_fd(": command not found", STDERR);
// 	else if (fd == -1 && folder == NULL)
// 		ft_putstr_fd(": No such file or directory", STDERR);
// 	else if (fd == -1 && folder != NULL)
// 		ft_putstr_fd(": is a directory", STDERR);
// 	else if (fd != -1 && folder == NULL)
// 		ft_putstr_fd(": Permission denied", STDERR);
// 	if (ft_strchr(path, '/') == NULL || (fd == -1 && folder == NULL))
// 		ret = UNKNOWN_COMMAND;
// 	else
// 		ret = IS_DIRECTORY;
// 	if (folder)
// 		closedir(folder);
// 	if (fd != -1)
// 		close(fd);
// 	return (ret);
// }

// int	ft_execution(char *path, char **args, t_data *data)
// {
// 	// char	**env_array;
// 	// char	*ptr;
// 	int		ret;
// 	char **env;

// 	ret = SUCCESS;
// 	env = ft_get_paths(data->envp);
// 	g_signal.pid = fork();
// 	if (g_signal.pid == 0)
// 	{
// 		// ptr = ft_env_to_str(env);
// 		// env_array = ft_split(ptr, '\n');
// 		// ft_memdel(ptr);
// 		if (ft_strchr(path, '/') != NULL)
// 			execve(path, args, env);
// 		ret = error_message(path);
// 		// free_tab(env_array);
// 		ft_clear_tokens(&data->tokens);
// 		exit(ret);
// 	}
// 	else
// 		waitpid(g_signal.pid, &ret, 0);
// 	if (g_signal.sigint == 1 || g_signal.sigquit == 1)
// 		return (g_signal.exit_status);
// 	ret = (ret == 32256 || ret == 32512) ? ret / 256 : !!ret;
// 	return (ret);
// }
