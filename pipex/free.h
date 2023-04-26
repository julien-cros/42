/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:49:01 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:28:12 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "struct.h"
# include "strs.h"

void	ft_free_pipex(t_pipex *pipex);
void	ft_free_2d_with_i(char ***strs, int i);
void	ft_free_with_i(char **strs, int i);

#endif