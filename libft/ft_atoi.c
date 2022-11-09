/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:06:42 by jcros             #+#    #+#             */
/*   Updated: 2022/11/09 12:33:22 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *nptr)
{
    int i;
    int sign;
    int res;
    
    i = 0;
    res = 0;
    sign = 1;
    while (nptr[i] >= 9 && nptr[i] <= 13 || nptr[i] == ' ')
        i++;
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
            sign *= -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        res *= 10;
        res = res + nptr[i] - 48;
        i++;
    }
    return (res *= sign);
}