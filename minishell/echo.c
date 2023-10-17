/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:07:23 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 13:08:32 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "echo.h"
#include "str.h"
#include "str2.h"
#include "env.h"
#include "display.h"
#include "args.h"
#include <stdio.h>
#include <stdbool.h>


static int		ft_print_the_path(char *arg, int out_fd, t_data *data, int type);
static int		ft_print_antislash(char *args, int i, int out_fd, int type);
static bool		ft_is_antislash(char c , int type, int care_of_quote);

int	ft_echo(t_token *token, t_data *data)
{
	char **args;
	char option;
	int i;
	int j;
	int type;

	args = ft_set_args(token);
	i = 0;
	j = 0;
	type = 2;
	if ((args[0][0] == '-') && ((args[0][1] == 'n' || args[0][1] == 'e' || args[0][1] == 'E'))) //  && !args[1]) je sais pas pourquoi
		option = args[i++][1];
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if(token->type != 2)
				type = token->type;
			if (type != TOKEN_SQ && args[i][j] == '$')
					j += ft_print_the_path(args[i], data->out_fd, data, type);
			else if (option == 'E' && ft_is_antislash(args[i][j] , type, 1) && args[i][j] != '\'' && args[i][j] != '\"')
				j += ft_putchar_fd(args[i][j], 1);
			else
				j += ft_print_antislash(args[i], j, data->out_fd, type);
		}
		if (type != TOKEN_SQ && type != TOKEN_DQ)
			ft_putchar_fd(' ', data->out_fd);
		i++;
		token = token->next;
	}
	if (!option || option != 'n')
		ft_putchar_fd('\n', data->out_fd);
	return (true);
}

int	ft_print_the_path(char *arg, int out_fd, t_data *data, int type)
{
	int i;
	int j;
	char *path;
	char *env_path;

	i = 0;
	j = 1;
	while (arg[i] && arg[i] != '$')
		i++;
	while (arg[i + j] && arg[i + j] != ' ' && !ft_is_antislash(arg[i + j], type, 0))
		j++;
	path = ft_substr(arg, i+1, j-1);
	env_path = ft_get_env_value(path, data->envp);
	if (env_path != NULL)
		ft_putstr_fd(env_path, out_fd);
	free(path);
	return (j);
}

bool	ft_is_antislash(char c, int type, int care_of_quote)
{
	if (care_of_quote == 1)
	{
		if (type == TOKEN_DQ && c == '\'')
			return (false);
		if (type == TOKEN_SQ && c == '\"')
			return (false);
	}
	if (c == '\\' || c == '\'' || c == '\"' ||   c == '\n' || c == '\t' || c == '\v' || c == '\b' || c == '\r' || c == '\f' || c == '\a')
		return (true);
	return (false);
}

int	ft_print_antislash(char *args, int i, int out_fd, int type)
{
	int j;

	j = 0;
		if (args[i] == '\\')
		{
			if (args[i + 1] == 'n')
				ft_putchar_fd('\n', out_fd);
			else if (args[i + 1] == 't')
				ft_putchar_fd('\t', out_fd);
			else if (args[i + 1] == 'v')
				ft_putchar_fd('\v', out_fd);
			else if (args[i + 1] == 'b')
				ft_putchar_fd('\b', out_fd);
			else if (args[i + 1] == 'r')
				ft_putchar_fd('\r', out_fd);
			else if (args[i + 1] == 'f')
				ft_putchar_fd('\f', out_fd);
			else if (args[i + 1] == 'a')
				ft_putchar_fd('\a', out_fd);
			j++;
		}
		else if (!ft_is_antislash(args[i], type, 1))
			ft_putchar_fd(args[i], out_fd);
		j++;
	return (j);
}