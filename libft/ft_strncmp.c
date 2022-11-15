/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:53:12 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/15 17:25:17 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    if (n <= 0)
        return (0);
    while (s1[i] && s1[i] == s2[i] && i < n-1)
        i++;
    return(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
