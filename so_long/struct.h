/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:46:16 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 15:12:15 by jcros            ###   ########.fr       */
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
	int y;
	int z;
	int collectible;
	t_bool exit;
	t_bool spawn;
	t_bool finishable;
	char **plan;
	
} t_map;

#endif