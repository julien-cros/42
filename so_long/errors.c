/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:57:50 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/22 18:24:42 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_invalid_map(void)
{
	ft_putstr_fd("Error: Invalid map.\n", 1);
}

void	ft_error(void)
{
	ft_putstr_fd("Error.\n", 1);
	exit(0);
}
