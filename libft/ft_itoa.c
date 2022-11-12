/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:01:58 by jcros             #+#    #+#             */
/*   Updated: 2022/11/12 15:50:10 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

char *fill_str(char *str, int i, int n)
{    
    while (i > 0)
    {
        str[i] = n % 10 + 48;
        n /= 10;
     //   printf("%c", str[i]);
        i--;
    }
    return (str);
}

char *ft_itoa(int n)
{
    int i;
    int cpy;
    char *str;

    i = 0;
    cpy = n;
    while (cpy > 0)
    {
        cpy /= 10;
        i++;
    }
    //printf("%d\n", i);
    str = (char *)malloc((sizeof(char)) * (i + 1));
    if (!str)
        return NULL;
    str[i+1] = '\0';
    //printf("mok\n n:%d\n", n);
    str = fill_str(str, i, n);
    //printf("%c\n", str[2]);
    return (str);
}

// int main()
// {
//     int n = 123;
//     ft_itoa(n);
//     return (0);
// }