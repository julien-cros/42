/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:04 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/03 22:34:08 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	bytes;

	bytes = 1;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	if (n == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return (10);
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (11);
	}
	if (n < 0)
	{
		bytes += ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		bytes += ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
	return (bytes);
}
