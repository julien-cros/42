/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:57:50 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/20 15:52:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	ft_invalid_map()
{
	ft_putstr_fd("Error: Invalid map.\n", 1);
}

void ft_error()
{
	ft_putstr_fd("Error.\n", 1);
}