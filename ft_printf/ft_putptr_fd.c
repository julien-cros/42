/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:40:16 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/02 17:17:44 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putptr_fd(void *ptr, int fd)
{
	return (ft_putnbr_base_fd((unsigned long)ptr, "123456789abcdef", fd));
}