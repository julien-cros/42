/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:18:01 by jcros             #+#    #+#             */
/*   Updated: 2022/11/07 17:11:43 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove (void *dest, const void *src, size_t n)
{
	int i;
	char *buffer[n+1];
	
	i = 0;
	while (i < n)
	{
		buffer[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while(i < n)
	{
		((char *)dest)[i] = buffer[i];
		i++;  
	}
	return (dest);
}
