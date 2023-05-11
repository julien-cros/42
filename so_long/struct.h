/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:46:16 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/11 14:01:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

# include "mlx/mlx.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_map
{
	int length;
	int row;
	int collectible;
	int exit;
	int spawn;
	t_bool is_valid;
	char *plan;
	int start_raw_pos;
	int start_col_pos;
	int i;
	int j;
	char index;
	char **strs;
	void *addr;
	void *img;
	void *win;
	void *mlx;
} t_map;

#endif