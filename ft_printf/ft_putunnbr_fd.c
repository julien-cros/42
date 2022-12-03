/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:50:31 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/03 22:35:20 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putunnbr_fd(unsigned int nb, int fd)
{
	int	bytes;

	bytes = 1;
	if (nb < 0)
		bytes += ft_putchar_fd('-', fd);
	if ( nb > 9)
		bytes += ft_putunnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + 48, fd);
	return (bytes);
}
