/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:01:58 by jcros             #+#    #+#             */
/*   Updated: 2022/11/13 18:53:41 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int size_n(n)
{
    int i;

    i = 0;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char *init_str(char *str, int n)
{
    int count;

    count = size_n(n);
    if (n < 0)
        count++;
    //printf("%d\n", count);
    str = (char *)malloc((sizeof(char) * (count + 1)));
    if (!str)
        return NULL;
    str[count + 1] = '\0';
     if (n < 0)
        str[0] = '-';
    return (str);
}

char *fill_str(char *str, int n)
{
    int i;

    i = size_n(n)-1;
    while (n)
    {
        str[i] = n % 10 + 48;
        n /= 10;
        i--;
        //printf("n = %d\nstr[%d] = %c\n", n, i, str[i]);
    }
    return (str);
}

char *ft_itoa(int n)
{
    char *str;

    if (n == 2147483647)
        return (ft_strdup("2147483647"));
    if (n == -2147483648)
        return (ft_strdup("-2147483648"));
    if (n == 0)
         return (ft_strdup("0"));
     str = NULL;
    str = init_str(str, n);
    if (!str)
        return NULL;
    if (n < 0)
        n *= -1;
    str = fill_str(str, n);
   // printf("final str = %s\n", str);
    return (str);
}

// int main ()
// {
//     int n = -1234;
//     printf("%s\n", ft_itoa(n));
// }