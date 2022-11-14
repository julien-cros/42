/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:01:58 by jcros             #+#    #+#             */
/*   Updated: 2022/11/14 11:27:11 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

 int size_n(int n)
{
    int count;
    unsigned int cpy;
    
    count = 0;
    if (n < 0)
    {
        count ++;
        n *=-1;
    }
    cpy = n;
    while (cpy)
    {
        cpy /= 10;
        count++;
    }
    return (count);
}

char *fill_str(char *str, int n)
{
    int i;
    unsigned int cpy;
    
    i = size_n(n)-1;
    if (n < 0)
        n *= -1;
    cpy = n;
    while (cpy > 0)
    {
        str[i] = cpy % 10 + 48;
        cpy /= 10;
        i--;
    }
    return (str);
}

char *ft_itoa(int n)
{
    char *str;
    int len;
    
    if (n == 0)
        return (ft_strdup("0"));
    len = size_n(n);
    str = (char *)ft_calloc(len + 1, sizeof(char));
    if(!str)
        return NULL;
    if (n < 0)
        str[0] = '-'; 
    str = fill_str(str, n);
    return (str);
}