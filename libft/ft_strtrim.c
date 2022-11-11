/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:04:03 by jcros             #+#    #+#             */
/*   Updated: 2022/11/11 14:22:13 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int is_set(char *str, char *set)
{
    int i = 0;
}

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int j;
    int size;
    char *str;
    
    i = -1;
    while (s1[++i])
    {
        if (!ft_strncmp(s1[i], set, ft_strlen(set)))
            size++;
    }
    str = (char *)ft_calloc(size+1, sizeof(char));
    i = -1;
    j = -1;
    while (s1[++i])
    {
        if (ft_strncmp(s1[i], set, ft_strlen(set)))
            i += ft_strlen(set);
        str[++j] = s1[i];
    }
    return (str);
}