/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:12:12 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/14 19:02:02 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find_cmd.h"
#include "split.h"
#include "str.h"
#include "str2.h"
#include "free.h"
#include "mem.h"
#include "parse.h"
#include "env.h"
#include "find.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static char	*ft_find_path(t_data *data, char *cmd);
static char	*ft_fmt_path(char *path, char *cmd);

/**
 * @brief The ft_set_path function sets the path of the command.
 * If the command is a builtin, the path is set to NULL. If the command
 * is not a builtin, the path is set to the full path of the command
 * found in the PATH environment variable.
 * 
 * @param data 
 * @param token 
 * @return char *
 */
char	*ft_set_path(t_data *data, t_token *token)
{
	char	*cmd;
	char	*path;
	int		cmd_len;

	if (ft_is_io_symbol(token))
		token = token->next->next;
	if (!token || token->type == TOKEN_PIPE || data->is_builtin == 1)
		return (NULL);
	cmd = ft_substr(token->value, 0, token->length);
	if (ft_strncmp(cmd, "/bin/", 5) == 0)
	{
		if (access(cmd, F_OK) != -1)
			return (cmd);
	}
	path = ft_find_path(data, cmd);
	if (!path)
		return (NULL);
	return (path);
}

/**
 * @brief The ft_find_path function finds the path of the command
 * in the PATH environment variable.
 *
 * @param cmd
 * @return char*
 */
static char	*ft_find_path(t_data *data, char *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	if (access(cmd, F_OK) == 0)
		return (ft_substr(cmd, 0, ft_strlen(cmd)));
	paths = ft_get_paths(data->envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		path = ft_fmt_path(paths[i], cmd);
		if (!path)
			return (ft_free_array(paths, -1), NULL);
		if (access(path, F_OK) == 0)
			return (ft_free_array(paths, -1), path);
		free(path);
	}
	return (ft_free_array(paths, -1), NULL);
}

/**
 * @brief The ft_fmt_path function returns the full path of the command.
 *
 * @param path
 * @param cmd
 * @return char*
 */
static char	*ft_fmt_path(char *path, char *cmd)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(path) + ft_strlen(cmd) + ft_strlen("/");
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (*path)
		str[i++] = *path++;
	str[i++] = '/';
	while (*cmd)
		str[i++] = *cmd++;
	str[i] = '\0';
	return (str);
}
