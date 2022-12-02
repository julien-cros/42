/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:50:31 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/01 16:04:53 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int ft_putunnbr_fd(unsigned int nb, int fd)
{
	if (nb < 0)
		ft_putchar_fd('-', fd);
	if ( nb > 9)
		ft_putunnbr_fd(nb / 10 ,fd);
	ft_putchar_fd(nb % 10 + 48, fd);
	return (0);
}
