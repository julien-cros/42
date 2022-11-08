/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:05:12 by jcros             #+#    #+#             */
/*   Updated: 2022/11/08 15:28:18 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char *ft_strchr(const char *s, int c)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return (s + i); //pointuer de s + i (index de la position ou je suis)
        i++;
    }
    return (0);
}