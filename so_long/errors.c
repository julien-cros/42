/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:57:50 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/21 12:47:58 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_invalid_map()
{
	ft_putstr_fd("Error: Invalid map.\n", 1);
}

void ft_error()
{
	ft_putstr_fd("Error.\n", 1);
	exit(0);
}