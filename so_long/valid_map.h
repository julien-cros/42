/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:48:00 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/10 18:37:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_H
#define VALID_MAP_H

#include "struct.h"
#include "errors.h"
#include "utils.h"
#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int ft_valid_map(t_map *map, int fd);

#endif