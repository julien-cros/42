/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:50:28 by jcros             #+#    #+#             */
/*   Updated: 2022/11/16 21:34:51 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_memcpy (void *dest, const void *src, size_t n)
{
	size_t i;
	
	i = 0;
	if (!dest && !src)
		return NULL;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i]; 
		i++;
	}
	return (dest);
}	