/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:57:39 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 16:36:32 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins_func.h"
#include "env.h"
#include "display.h"
#include "str.h"
#include "str2.h"
#include "args.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int		ft_cd(t_data *data)
{
	char	*path;
	int		ret;
	char	**args;

	ret = 0;
	args = ft_set_args(data->tokens);
	if (!args[1])
	{
		path = ft_get_env_value("HOME", data->envp);
		chdir(path);
	}
	else if (args[2])
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		ret = 1;
	}
	else if (chdir(args[1]) == -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		ret = 1;
	}
	ft_pwd(data);
	return (ret);
}

int		ft_pwd(t_data *data)
{
	char	*path;

	path = getcwd(NULL, 100);
	ft_putstr_fd(path, data->out_fd);
	ft_putstr_fd("\n", data->out_fd);
	free(path);
	return (0);
}

// // int		ft_export(t_subcommand *subcommand)
// // {
// // 	char **args;
// // 	int i;
// // 	int j;

// // 	args = subcommand->args;
// // 	i = 0;
// // 	j = 0;
// // 	if (!args)
// // 		ft_env(subcommand);
// // 	if (args && !args[i+1] && ft_strncmp(args[i], "=", 1) != 0)
// // 		ft_set_env(args[i], "", subcommand);
// // 	while (args && args[i] && ft_strncmp(args[i], "=", 1) != 0)
// // 		i++;
// // 	while (args && args[i + j])
// // 	{
// // 		if (ft_strchr(args[i], '='))
// // 			ft_set_env(args[i-1], args[i+1], subcommand);
// // 		i++;
// // 	}
// // 	else
// // 		ft_putstr_fd("export: not a valid identifier\n", 2);
// // 	return (0);
// // }

// int ft_export(t_subcommand *subcommand)
// {
// 	char **args;
// 	int i;
// 	int j;

// 	args = subcommand->args;
// 	i = -1;
// 	j = 0;
// 	if (!args)
// 		return (ft_env(subcommand));
// 	while (args[++i] && ft_strncmp(args[i], "=", 1) != 0)
// 			ft_set_env(args[i], "");
// 	if (args[i] && ft_strncmp(args[i], "=", 1) == 0 && i == 1 && !args[i++])
// 		ft_set_env(args[i], args[i]);
// 	if (args[i+1])
// 		ft_putstr_fd("export: bad assignment\n", 2);
// 	return (0);
	
// }

// int		ft_unset(t_subcommand *subcommand)
// {
// 	char **args;
// 	int i;

// 	args = subcommand->args;
// 	i = 0;
// 	while (args[i])
// 	{
// 		ft_remove_env(args[i]);
// 		i++;
// 	}
// 	return (0);
// }

int		ft_env(t_data *data)
{
	t_env	*tmp;
	
	tmp = data->envp;
	while (tmp)
	{
		ft_putstr_fd(tmp->value, data->out_fd);
		ft_putstr_fd("\n", data->out_fd);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_exit(t_data *data)
{
	int		i;
	char	**args;

	i = 0;
	if (data->tokens->next)
	{
		printf("ok\n");
		args = ft_set_args(data->tokens);
		if (args[1] && args[2])
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
		else if (args[1])
			i = ft_atoi(args[1]);
	}
	exit(i);
}
