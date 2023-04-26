/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:40:16 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/03 22:30:35 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_fd(void *ptr, int fd)
{
	if (!ptr)
		return (write(1, "0x0", 3));
	ft_putstr_fd("0x", fd);
	return (ft_putnbr_base_fd((unsigned long)ptr, "0123456789abcdef", fd) + 2);
}
