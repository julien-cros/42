/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 08:47:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/24 10:54:37 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map.h"

t_map *ft_valid_map(t_map *map, int fd)
{
	char buffer;

	if (!read(0, buffer, 0))
		return(ft_no_map(), NULL);
	else 
		printf("not ok");
	return (map);
}