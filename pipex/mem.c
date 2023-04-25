/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:41:34 by jcros             #+#    #+#             */
/*   Updated: 2023/04/25 13:49:15 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mem.h"

void	ft_bzero(void *s, size_t n)
{
	return ((void)ft_memset(s, 0, n));
}
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = s;
	while (i < n)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
