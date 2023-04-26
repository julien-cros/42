/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:48:25 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/03 22:34:37 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	bytes;

	bytes = 0;
	i = 0;
	if (!fd)
		return (0);
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		bytes += write(fd, &s[i], 1);
		i++;
	}
	return (bytes);
}
