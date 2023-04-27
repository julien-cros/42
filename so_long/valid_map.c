/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:47:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 14:56:26 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map.h"

t_map *ft_valid_map(t_map *map, int fd)
{
	char buffer;

	if (read(0, buffer, 0))
		printf("ok\n");
	else 
		printf("not ok\n");
	return (map);
}