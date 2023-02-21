/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:00:51 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/18 18:24:38 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"

int ft_atoi(const char *nptr)
{
	int i;
	int sign;
	int res;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res = res + nptr[i] - 48;
		i++;
	}
	return (res *= sign);
}

void ft_putnbr_fd(int n, int fd)
{
	if (n == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return;
	}
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
	size_t i;

	i = 0;
	if (!s || !fd)
		return;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
