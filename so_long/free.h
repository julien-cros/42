/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:28:35 by codespace         #+#    #+#             */
/*   Updated: 2023/05/10 18:06:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
#define FREE_H

#include "struct.h"
#include <stdlib.h>

void ft_clean(t_map *map);
void	ft_free_with_i(char **strs);

#endif