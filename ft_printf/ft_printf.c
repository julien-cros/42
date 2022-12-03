/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:26:31 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/03 22:37:37 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char s, va_list *ap);
static int	ft_is_legal(char s1, char s2);

int	ft_printf(const char *format, ...)
{
	int	i;
	int	bytes;
	va_list	ap;

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
	va_end(ap);
	return (bytes);
}

static int	ft_is_legal(char s1, char s2)
{
	const char	*legal = "cspdiuxX";

	if (s1 == '%' && ft_strchr(legal, s2))
		return (1);
	return (0);
}

static int	ft_print(char s, va_list *ap)
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
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), "0123456789abcdef", 1));
	if (s == 'X')
		return (ft_putnbr_base_fd(va_arg(*ap, unsigned int), "0123456789ABCDEF", 1));
	return (0);
}
