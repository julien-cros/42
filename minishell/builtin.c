/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:37:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 16:46:29 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "str.h"
#include "str2.h"
#include "builtins_func.h"
#include "echo.h"
#include "export.h"
#include  <stdio.h>



// bool	ft_builtin(t_data *data, t_token *token)
// {
// 	t_builtin	*builtin;
// 	char 		*path;

// 	path = (char *)token->value;
// 	path[token->length] = '\0';
// 	if (ft_if_builtin(path))
// 		return (ft_builtin_valid(token, data, path), true);
// 	return (false);
// }

bool	ft_if_builtin(char *cmd)
{
	if ((ft_strncmp(cmd, "echo", 4) == 0 && ft_strlen(cmd) == 4) ||
	(ft_strncmp(cmd, "cd", 2) == 0 && ft_strlen(cmd) == 2) ||
	(ft_strncmp(cmd, "pwd", 3) == 0 && ft_strlen(cmd) == 3) ||
	(ft_strncmp(cmd, "export", 6) == 0 && ft_strlen(cmd) == 6) ||
	(ft_strncmp(cmd, "unset", 5) == 0 && ft_strlen(cmd) == 5) ||
	(ft_strncmp(cmd, "env", 3) == 0 && ft_strlen(cmd) == 3) ||
	(ft_strncmp(cmd, "exit", 4) == 0 && ft_strlen(cmd) == 4))
		return (true);
	return (false);
}

bool	ft_builtin_valid(t_token *token, t_data *data, char *cmd)
{
	if (data->out_fd == -1)
		data->out_fd = STDOUT_FILENO;
	if (ft_strncmp(cmd, "echo", 4) == 0 && token->next)
		data->return_status = ft_echo(token->next, data);
	if (ft_strncmp(cmd, "cd", 2) == 0)
		data->return_status = ft_cd(data);
	if (ft_strncmp(cmd, "pwd", 3) == 0)
		data->return_status = ft_pwd(data);
	if (ft_strncmp(cmd, "export", 6) == 0)
		ft_export(data);
	// if (ft_strncmp(cmd, "unset", 5) == 0 && token->next && !token->next->next)
	// 	return (ft_unset(data), true);
	if (ft_strncmp(cmd, "env", 3) == 0	)
		ft_env(data);
	if (ft_strncmp(cmd, "exit", 4) == 0)
		ft_exit(data);
	data->out_fd = -1;
	return (true);
}