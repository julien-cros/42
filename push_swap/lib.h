/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:56:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/02 16:40:33 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
#define LIB_H

#include "lists.h"

void ft_sort_args(int *args, int size);
void ft_sort_three(t_list **a);
void ft_sort_five(t_list **a, t_list **b);
void ft_sort_large(t_list **a, t_list **b, int size);

#endif
