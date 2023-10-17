/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_levels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:09:26 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/13 20:07:24 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell_levels.h"
#include "str.h"
#include "mem.h"
#include "env.h"
#include "int.h"

/**
 * @brief The ft_is_invalid_lvl function checks if the string passed as parameter
 * is a valid number. If it is not, it returns 1, else it returns 0.
 * 
 * @param str 
 * @return int 
 */
static int			ft_is_invalid_lvl(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief The ft_skip_spacenl function skips all the spaces, tabs, newlines,
 * carriage returns, vertical tabs and form feeds in the string passed as
 * parameter.
 * 
 * @param str 
 * @param i 
 */
void	ft_skip_spacenl(const char *str, int *i)
{
	while ((str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n')
	|| (str[*i] == '\r' || str[*i] == '\v' || str[*i] == '\f'))
		(*i)++;
}

/**
 * @brief The ft_get_lvl function returns the shell level as an int.
 * 
 * @param str 
 * @return int 
 */
static int			ft_get_lvl(const char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	ft_skip_spacenl(str, &i);
	if (ft_is_invalid_lvl(str))
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

/**
 * @brief The ft_increment_shell_level function increments the shell level
 * environment variable.
 * 
 * @param env 
 */
void	ft_increment_shell_level(t_env *env)
{
	int		shell_level;
	char	env_name[BUFFER_SIZE];
	char	*shlvl;
	char	*shell_level_value;

	shell_level_value = ft_get_env_value("SHLVL", env);
	if (ft_strncmp(shell_level_value, "", 1) == 0)
		return ;
	shell_level = ft_get_lvl(shell_level_value) + 1;
	ft_memdel(shell_level_value);
	while (env && env->next)
	{
		ft_get_env_name(env_name, env->value);
		if (ft_strncmp("SHLVL", env_name, 5) == 0)
		{
			ft_memdel(env->value);
			shlvl = ft_itoa(shell_level);
			env->value = ft_strjoin("SHLVL=", shlvl);
			ft_memdel(shlvl);
			return ;
		}
		env = env->next;
	}
}
