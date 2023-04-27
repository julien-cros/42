/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:48:00 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 16:41:41 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_H
#define VALID_MAP_H

#include "struct.h"
#include "errors.h"
#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

t_map *ft_valid_map(t_map *map, int fd);

#endif