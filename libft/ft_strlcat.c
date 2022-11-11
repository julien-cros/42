/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:46:45 by jcros             #+#    #+#             */
/*   Updated: 2022/11/11 17:58:26 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;
    size_t size_dst;
    size_t size_src;
    
    i = 0;
    size_dst = ft_strlen(dst);
    size_src = ft_strlen(src);
    if (size == 0)
        return (size_src);
    if (size_dst >= size)
        return (size + size_src);
    while (src[i] && i < size -size_dst-1)
    {
        dst[i+ size_dst] = src[i];
        i++;
    }
    dst[i + size_dst] = '\0';
    return (size_dst + size_src);
}