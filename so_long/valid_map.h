/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:48:00 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/24 10:52:47 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_H
#define VALID_MAP_H

#include "struct.h"
#include "errors.h"
#include <fcntl.h>
#include <stdio.h>

t_map *ft_valid_map(t_map *map, int fd);

#endif