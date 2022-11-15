/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:18:01 by jcros             #+#    #+#             */
/*   Updated: 2022/11/15 17:07:25 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove (void *dest, const void *src, size_t n)
{
	if( (long int)src < (long int)dest)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else 
		return (ft_memcpy(dest, src, n));
	return (dest);
}

// void    *ft_memmove(void *dest, const void *src, size_t n)
// {
//     size_t i;
//     // char    *bdest;
//     // const char  *bsrc;

//     i = 0;
// //    bdest = dest;
// //    bsrc = src;
//     if ((long int)dest > (long int)src)
//         while (i++ < n)
//             ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
//     else
//             ft_memcpy(dest, src, n);
//     return (dest);
// }