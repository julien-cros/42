/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:45:50 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/12 10:58:05 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAYS_H
# define ARRAYS_H

# include "structs.h"

void	ft_sort_int_array(int **arr, int size);
t_list	*ft_fill_list_with_args(int *args, int size);

#endif
