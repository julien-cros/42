/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:46:16 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/22 18:41:29 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "mlx/mlx.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_map
{
	int		length;
	int		row;
	int		collectible;
	int		exit;
	int		spawn;
	t_bool	is_valid;
	char	*plan;
	int		start_raw_pos;
	int		start_col_pos;
	int		i;
	int		j;
	char	index;
	char	**strs;
	int		fd;
}	t_map;

typedef struct s_data
{
	void	*img[5];
	void	*win;
	void	*mlx_ptr;
	char	**img_path;
	char	**map;
	int		position_x;
	int		position_y;
	int		i;
	int		j;
	int		length;
	int		row;
	int		collectible;
	int		exit;
	int		keycode;
	int		player_x;
	int		player_y;
	int		step;
}	t_data;
#endif
