/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:43:17 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/03 14:36:18 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "parse.h"
#include "strings.h"
#include "split.h"

t_args *ft_parse_args(int argc, char **argv)
{
	int i;
	t_args *arg;

	if (argc == 2)
		arg = ft_split_args(argv[1]);
	else
		arg = get_args(argc, argv);
	ft_check_num(arg, arg->count);
	arg->int_array = malloc(sizeof(int) * (arg->count));
	i = -1;
	while (++i < arg->count)
	{
		if (ft_atoi(arg->str_array[i]) > INT_MAX || ft_atoi(arg->str_array[i]) < INT_MIN)
		{
			free(arg->int_array);
			if (arg->is_malloced)
				ft_free(arg->str_array, arg->count);
			return (free(arg), ft_putstr_fd("Error\n", 2), exit(1), NULL);
		}
		arg->int_array[i] = (int)ft_atoi(arg->str_array[i]);
	}
	ft_check_duplicate(arg);
	return (arg);
}

t_args *ft_split_args(char *str)
{
	t_args *arg;
	char **args;
	int i;

	args = ft_split(str, ' ');
	if (!args)
		return (ft_putstr_fd("Error\n", 2), exit(1), NULL);
	arg = malloc(sizeof(t_args));
	if (!arg)
		return (ft_putstr_fd("Error\n", 2), exit(1), NULL);
	i = -1;
	while (args[++i])
		;
	arg->count = i;
	arg->str_array = args;
	arg->int_array = NULL;
	arg->is_malloced = true;
	return (arg);
}

t_args *get_args(int argc, char **argv)
{
	t_args *arg;

	arg = malloc(sizeof(t_args));
	if (!arg)
		return (ft_putstr_fd("Error\n", 2), exit(1), NULL);
	arg->count = argc - 1;
	arg->str_array = argv + 1;
	arg->int_array = NULL;
	arg->is_malloced = false; // pourquoi false;
	return (arg);
}

void ft_check_num(t_args *arg, int count)
{
	int i;

	while (count-- > 0)
	{
		i = 0;
		while (arg->str_array[count][i])
		{
			if ((i == 0 && arg->str_array[count][i] == '-') || (i == 0 && arg->str_array[count][i] == '+'))
				i++;
			if (arg->str_array[count][i] >= 48 && arg->str_array[count][i] <= 57)
				i++;
			else
			{
				if (arg->is_malloced)
					ft_free(arg->str_array, count);
				return (free(arg), ft_putstr_fd("Error\n", 2), exit(1));
			}
		}
	}
}

void ft_check_duplicate(t_args *arg)
{
	int i;
	int j;

	i = -1;
	while (++i < arg->count)
	{
		j = i;
		while (++j < arg->count)
		{
			if (arg->int_array[i] == arg->int_array[j] && i != j)
			{
				free(arg->int_array);
				if (arg->is_malloced)
					ft_free(arg->str_array, arg->count);
				free(arg);
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
		}
	}
}