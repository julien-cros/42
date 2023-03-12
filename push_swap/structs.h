/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:05:42 by jcros             #+#    #+#             */
/*   Updated: 2023/03/12 11:06:16 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_args
{
	char	**str_array;
	int		*int_array;
	int		count;
	t_bool	is_str_array_alloced;
}				t_args;

typedef struct s_list
{
	int				v;
	struct s_list	*n;
}	t_list;

#endif
