/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:46:45 by jcros             #+#    #+#             */
/*   Updated: 2022/11/08 11:53:36 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    int i;
    int size_dst;
    int size_src;
    
    i = 0;
    size_dst = ft_strlen(dst);
    size_src = ft_strlen(src);
    if (size_dst > size)
        return (size + size_src);
    while ((i < size_src) && (size_dst -1) - size != '\0')
    {
        dst[i+ size_dst] = src[i];
        i++;
    }
    dst[i + size_dst] = '\0';
    return (size_dst + i);
}