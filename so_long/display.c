/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:59:34 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/24 10:04:24 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"


void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void ft_puchar_fd(char c, int fd)
{
	if (!c || !fd)
		return ;
	write(fd, &c, 1);
}
