/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:56:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/12 11:06:54 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "structs.h"

void	ft_sort_args(int *args, int size);
void	ft_sort_three_array(t_list **a);
void	ft_sort_five_array(t_list **a, t_list **b);
void	ft_sort_large_array(t_list **a, t_list **b, int size);

#endif
