/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_finishable.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:22:30 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/04 10:42:01 by juliencros       ###   ########.fr       */
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

int if_can(t_map *map);

#endif