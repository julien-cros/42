/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:57:50 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/04 21:42:50 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

void	ft_no_map()
{
	ft_putstr_fd("Can't find the map\n", 1);
}

void	error_lenght_line()
{
	ft_putstr_fd("Error: The map isn't rectangle.\n", 1);
}

void	error_wrong_character(char c)
{
	write(1,"Error: ",7);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(". Not a valid argument in the map.\n", 1);
}

void	error_square()
{
	ft_putstr_fd("Error: Your map is a square.", 1);
}

void	error_wall()
{
	ft_putstr_fd("Error: The walls are not encompasses the map.", 1);
}

void	ft_error_finding_exit()
{
	ft_putstr_fd("Error: Can't find the exit.", 1);
}