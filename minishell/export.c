/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:00:23 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 19:19:12 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "export.h"
#include "args.h"
#include "display.h"
#include "split.h"
#include "free.h"
#include "str.h"
#include "env.h"

void	ft_print_export(t_env *envp)
{
	t_env *tmp;
	char **splitted_args;

	tmp = envp;
	while (tmp)
	{
		splitted_args = ft_split(tmp->value, '=');
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(splitted_args[0], STDOUT_FILENO);
		if (tmp->value)
		{
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(splitted_args[1], STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		ft_free_tab(splitted_args);
		tmp = tmp->next;
	}
}


void	ft_set_env(t_env *envp, char *key, char *value)
{
	int	i;
	int	j;
	t_env *head;

	i = 0;
	head = envp;
	while (envp)
	{
		j = 0;
		while (envp->value[j] && envp->value[j] != '=')
			j++;
		if (ft_strncmp(envp->value, key, j) == 0)
		{
			free(envp->value);
			envp->value = ft_strjoin(key, value);
			return ;
		}
		envp = envp->next;
	}
	envp = head;
	return ;
}

int		ft_export(t_data *data)
{
	char **args;
	int i;

	args = ft_set_args(data->tokens);
	printf("args[0] = %s\n", args[0]);
	i = 1;
	if (!args[i])
		return (ft_print_export(data->secret_env), 0);
	else
{
		while (args[++i] && ft_strncmp(args[i], "=", 1) != 0)
		{
			ft_set_env(data->envp, args[i], "");
			ft_set_env(data->secret_env, args[i], "");
		}
		if (args[i] && ft_strncmp(args[i], "=", 1) == 0 && i == 1 && !args[i++])
		{
			ft_set_env(data->envp, args[i], args[i]);
			ft_set_env(data->secret_env, args[i], args[i]);
		}
		if (args[i+1])
			return(ft_putstr_fd("export: bad assignment\n", 2), 1);

	}
	return (0);
}