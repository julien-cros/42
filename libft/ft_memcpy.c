/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:50:28 by jcros             #+#    #+#             */
/*   Updated: 2022/11/07 17:08:57 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_memcpy (void *dest, const void *src, size_t n)
{
	int i;
	
	i = 0;
	
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i]; 
		i++;
	}
	return (dest);
}	