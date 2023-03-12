/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:51:57 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/02 18:06:58 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strings.h"
#include "display.h"
#include <unistd.h>

static void ft_putchar_fd(char s, int fd);

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (i[s])
		++i;
	return (i);
}

long ft_atoi(const char *nptr)
{
	long i;
	long sign;
	long res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 45 || nptr[i] == 43)
		if (nptr[i++] == 45)
			sign *= -1;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return ((long)(res * sign));
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *space;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	space = malloc(nmemb * size);
	if (!space)
		return (0);
	ft_memset(space, 0, nmemb * size);
	return (space);
}

void *ft_memset(void *s, int c, size_t n)
{
	while (n-- > 0)
		((char *)s)[n] = (unsigned char)c;
	return (s);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t i;
	char *str;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
	{
		str = (char *)ft_calloc(1, sizeof(char));
		if (!str)
			return (0);
		return (str);
	}
	if (ft_strlen(s) < len + start)
		str = (char *)ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s[start + ++i] && i < len)
		str[i] = s[start + i];
	return (str);
}

void ft_putchar_fd(char s, int fd)
{
	write(fd, &s, 1);
}

void ft_putnbr_fd(int n, int fd)
{
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
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}
