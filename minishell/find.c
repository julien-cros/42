/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:24:34 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 11:19:25 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "find.h"
#include <stdbool.h>

/**
 * @brief The ft_find_type function search for a token of a specific type in a
 * 		token list. If the token is found, the function returns true, else it
 * 		returns false. You can specify a max type to stop the search.
 * 
 * @param token 
 * @param type 
 * @param max 
 * @return true 
 * @return false 
 */
bool	ft_find_type(t_token *token, int type, int max)
{
	while (token && token->type != type && token->type != max)
		token = token->next;
	if (token && token->type == type)
		return (true);
	return (false);
}

bool	ft_find_prev_type(t_token *token, int type)
{
	while (token && token->type != type && token->type != TOKEN_PIPE)
		token = token->prev;
	if (token)
		return (true);
	return (false);
}

bool	ft_is_io_symbol(t_token *token)
{
	if (token && (token->type == TOKEN_LT || token->type == TOKEN_LT_LT
		|| token->type == TOKEN_GT || token->type == TOKEN_GT_GT))
		return (true);
	else
		return (false);
}
