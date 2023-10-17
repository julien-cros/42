/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:33:04 by herbie            #+#    #+#             */
/*   Updated: 2023/10/16 10:29:08 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "find.h"
#include "mem.h"
#include "str2.h"
#include <stdbool.h>

int	ft_args_count(t_token *token)
{
	t_token *tmp;
	int i;

	i = 0;
	tmp = token;
	while (tmp && tmp->type != TOKEN_PIPE)
	{
		if (ft_is_io_symbol(token))
			i -= 2;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**ft_set_args(t_token *token)
{
	t_token *tmp;
	char **args;
	int i;

	tmp = token;
	i = ft_args_count(token);
	if (i < 1 || !token)
		return (NULL);
	args = ft_calloc(i + 1, sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	while (tmp && tmp->type != TOKEN_PIPE)
	{
		if (ft_is_io_symbol(tmp))
			tmp = tmp->next->next;
		if (!tmp || tmp->type == TOKEN_PIPE)
			break ;
		args[i] = ft_substr(tmp->value, 0, tmp->length);
		tmp = tmp->next;
		i++;
	}
	args[i] = NULL;
	return (args);
}
