/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:26:31 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/02 14:06:50 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// # include <stdlib.h>
// # include <unistd.h>
// # include <stdarg.h>
// # include <stdio.h>
// # include <stdint.h>
// # include <limits.h>


static int ft_print(char s, va_list *ap);
static int ft_is_legal(char s1, char s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int	ft_putchar_fd(char c, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_putstr_fd(char *s, int fd);


int ft_printf(const char *format, ...)
{
	int i;
	int bytes;
	va_list ap;

	va_start(ap, format);
	i = 0;
	bytes = 0;
	while (format[i])
	{
		if (ft_is_legal(format[i], format[i + 1]))
			bytes += ft_print(format[++i], &ap);
		else
			bytes += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end (ap);
	return (bytes);
}

static int ft_is_legal(char s1, char s2)
{
  const char *legal = "cspdiuxX";
  
  if (s1 == '%' && ft_strchr(legal, s2))
    return (1);
  return (0);
}

static int ft_print(char s, va_list *ap)
{
	if (s == 'c')
		return (ft_putchar_fd(va_arg(*ap, int), 1));
	if (s == 's')
		return (ft_putstr_fd(va_arg(*ap, char *), 1));
	if (s == 'p')
		return (ft_putptr_fd(va_arg(*ap, void *), 1));
	if (s == 'd' || s == 'i')
		return (ft_putnbr_fd(va_arg(*ap, int), 1));
	if (s == 'u')
		return (ft_putunnbr_fd(va_arg(*ap, unsigned int), 1));
	if (s == 'x')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), "123456789abcdef", 1));
	if (s == 'X')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), "123456789ABCDEF", 1));
	return (0);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// int main ()
// {
// 	char c = 't';
// 	int nb = 1234;

// 	ft_printf("julien cros es%c beau et %d c'est cool", c, nb);
// }

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// int	ft_putnbr_fd(int n, int fd)
// {
// 	if (n == 2147483647)
// 	{
// 		ft_putstr_fd("2147483647", fd);
// 		return (0);
// 	}
// 	if (n == -2147483648)
// 	{
// 		ft_putstr_fd("-2147483648", fd);
// 		return (0);
// 	}
// 	if (n < 0)
// 	{
// 		ft_putchar_fd('-', fd);
// 		n *= -1;
// 	}
// 	if (n > 9)
// 		ft_putnbr_fd(n / 10, fd);
// 	ft_putchar_fd(n % 10 + 48, fd);
// 	return (0);
// }

// int	ft_putstr_fd(char *s, int fd)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s || !fd)
// 		return (0);
// 	while (s[i])
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// 	return (0);
// }

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	if (!c)
// 		return ((char *)s + ft_strlen(s));
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)s + i);
// 		i++;
// 	}
// 	return (0);
// }

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }