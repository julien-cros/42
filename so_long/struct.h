/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:46:16 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/04 12:06:13 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_map
{
	int length;
	int width;
	int collectible;
	int exit;
	int spawn;
	t_bool finishable;
	char *plan;
	int start_raw_pos;
	int start_col_pos;
	
	
} t_map;

#endif