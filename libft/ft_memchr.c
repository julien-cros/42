/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:58:16 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/08 18:21:32 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (((char *)s)[i] == (char)c)
            return(void *)(s + i);
        i++;
    }
    return (0);
}