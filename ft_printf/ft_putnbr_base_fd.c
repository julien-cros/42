/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:15:51 by juliencros        #+#    #+#             */
/*   Updated: 2023/12/08 10:01:36 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printnbr_fd(unsigned long n, char *base, int fd);

int	ft_putnbr_base_fd(unsigned long n, char *base, int fd)
{
	if (n == 0)
		return (ft_putchar_fd(base[0], fd));
	else
		return (ft_printnbr_fd(n, base, fd) - 1);
}

int	ft_printnbr_fd(unsigned long n, char *base, int fd)
{
	int	size;
	int	bytes;

	bytes = 1;
	size = ft_strlen(base);
	if (n)
	{
		bytes += ft_printnbr_fd(n / size, base, fd);
		ft_putchar_fd(base[n % size], fd);
	}
	return (bytes);
}
