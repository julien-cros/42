/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:53:12 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/10 13:27:06 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    int i;

    i = 0;
    if (n <= 0)
        return (0);
    while (((unsigned char *)s1)[i] && s1[i] == ((unsigned char *)s2)[i] && i < n-1)
        i++;
    return((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
}
