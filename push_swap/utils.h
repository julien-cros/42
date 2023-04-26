/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:51 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/12 11:05:20 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"

void	ft_free_args(t_args *arg, t_bool free_ints);
int		ft_highest_value(t_list *list);
int		ft_is_sorted(t_list *list);
int		ft_replace_args_by_indices(int **args, int size);
int		ft_get_index_of(t_list *lst, int value);

#endif