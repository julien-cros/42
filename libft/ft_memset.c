/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:47:02 by jcros             #+#    #+#             */
/*   Updated: 2022/11/07 16:47:27 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset (void *s, int c, size_t n)
{
    int i;
    char *buffer;

    i = 0;
    buffer = s;
    while (i < n)
    {
        buffer[i] = (unsigned char)c;
        i++;
    }
    return (s);
}