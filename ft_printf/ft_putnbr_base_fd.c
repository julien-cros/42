/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:15:51 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/02 17:20:56 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int	ft_putnbr_base_fd(unsigned long n, char *base, int fd)
{
	size_t size;
	int bytes;
	
	bytes = 1;
	size = ft_strlen(base);
	while(n > 0)
	{
		bytes += ft_putnbr_base_fd(n/size, base, fd);
		ft_putchar_fd(base[n % size], fd);
	}
		// ft_putchar_fd(base[n % size], fd);
		return (bytes);
}