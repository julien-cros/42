/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:04:03 by jcros             #+#    #+#             */
/*   Updated: 2022/11/11 21:02:58 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    int i;
    int j;
    int size;
    char *str;
    
    i = -1;
    size = 0;
    if (! s1 || !set)
        return (0);
    while (s1[++i])
    {
        while (s1[i] && ft_strchr(set, s1[i]))
            i += ft_strlen(set);
        size++;
    }
    str = (char *)ft_calloc(size+1, sizeof(char));
    if (!str)
        return NULL;
    i = -1;
    j = 0;
    while (++i < size)
    {
        if((!ft_strchr(set, s1[i])) && (ft_strchr(set, str[i+1])))
        {
            ft_substr(s1, i, j);
            j = i;
        }
    }
    return (str);
}

// {
//     size_t i;
//     size_t count;
    
//     if (!set || !s1)
//         return (0);
//     while ((char *)s1[i])
//     {
//         if (ft_strchr(set, s1[i]))
//         {
//             while (ft_strchr(set, (char *)s1[i]))
//             {
//                 i++;
//                 count++;
//             }
//         }
//         i++;
//     }
// }

// if (!ft_strncmp(&s1[i], (char *)set, ft_strlen(set)))
//             str[++j] = s1[i];