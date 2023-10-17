/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:25:09 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 11:19:43 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIND_H
# define FIND_H

# include "structs.h"
# include <stdbool.h>

bool	ft_find_type(t_token *token, int type, int max);
bool	ft_is_io_symbol(t_token *token);
bool	ft_find_prev_type(t_token *token, int type);

#endif