/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:44:18 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/02 16:43:56 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPS_H
#define OPS_H

#include "lists.h"
#include <stdlib.h>

void ft_rotate(t_list **list, char *op);
void ft_push(t_list **src, t_list **dst, char *op);
void ft_swap(t_list **list, char *op);
void ft_reverse_rotate(t_list **list, char *op);

#endif