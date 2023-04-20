/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:49:01 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/20 16:22:15 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
#define FREE_H

#include "struct.h"
#include "strs.h"

void	ft_free_pipex(t_pipex *pipex);
void	ft_free_2d(char **strs);
void	ft_free_3d(char ***strs);

#endif