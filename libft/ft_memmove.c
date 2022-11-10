/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:18:01 by jcros             #+#    #+#             */
/*   Updated: 2022/11/10 12:43:41 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove (void *dest, const void *src, size_t n)
{
	size_t i;

	i = n;
	if( (long int)src < (long int)dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else 
		return (ft_memcpy(dest, src, i));
	return (dest);
}
