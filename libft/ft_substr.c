/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:42:20 by jcros             #+#    #+#             */
/*   Updated: 2022/11/11 13:18:53 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
//     char *dup;
//     int i;
//     int end;
//     int j;
    
//     j = 0;
//     if (!s)
//         return (0);
//     if (ft_strlen(s) < start || start + len > ft_strlen(s))
//         return(ft_strdup(""));
//     if (start < len)
//     {
//         dup = (char *)ft_calloc((len - start)+1, sizeof(char));
//         i = start;
//         end = len;
//     }
//     else
//     {
//         dup = (char *)ft_calloc((start - len)+1, sizeof(char));
//         i = len;
//         end = start;
//     }
//     if (!dup)
//         return NULL;
//     while (i < end)
//     {
//         dup[j] = ((char *)s)[i];
//         i++;
//         j++;
//     }
//     return (dup);
// }


    char *dup;
    int sizedup;
    int i;
    
    if (!s)
        return (0);
    if (ft_strlen(s) < len || start + len > ft_strlen(s))
        return ("");
    if(len < start)
    {
        dup = (char *)ft_calloc(start - len + 1, sizeof(char));
        sizedup = start - len;
    }
    else
    {
        dup = (char *)ft_calloc(len - start + 1, sizeof(char));
        sizedup = len - start;
    }
    if(!dup)
        return NULL;
    i = sizedup+1;
    len += 1;
    start += 1;  
    while (i  > 0)
        dup[i--] = s[len-- + start--];
    return (dup); 
}



// "hello world" 3 8    -> str -> o wor
// "hello world" 7 4    -> str -> orld