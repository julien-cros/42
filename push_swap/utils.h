/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:51 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/02 16:43:43 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
#define UTILS_H

#include "lists.h"

int ft_replace_by_indices(int **args, int size);
t_list *ft_fill_list(int *args, int size);
int ft_is_sorted(t_list *list);
int ft_highest_value(t_list *list);
int ft_get_index_of(t_list *lst, int value);

#endif