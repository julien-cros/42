/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finishable.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:22:30 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/08 22:56:37 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_FINISHABLE_H
# define CHECK_FINISHABLE_H

#include "struct.h"
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
#include "utils.h"
#include "errors.h"

int if_can(t_map *map);
char	**ft_create_2d(t_map *map);
int		ft_find_exit(char **strs, t_map *map);
int ft_search_row(char **strs, t_map *map, char c);
int ft_search_col(char **strs, t_map *map, char c);
int ft_find_p(char **strs, t_map *map);
int ft_find_char(char **strs, t_map *map, char c);
int ft_get_back_i(char **strs, t_map *map);
int ft_get_back_j(char **strs, t_map *map);

#endif