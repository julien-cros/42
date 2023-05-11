/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:27:33 by codespace         #+#    #+#             */
/*   Updated: 2023/05/11 19:29:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
# include "mlx/mlx.h"

void ft_init_window( )// t_map *map)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	// if (!mlx)
	// 	return ;
	mlx_win = mlx_new_window(mlx, 600,  300, "Hello world!");
	mlx_loop(mlx);
	if (!mlx || !mlx_win)
		return ;
}