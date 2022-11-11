/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:54:19 by jcros             #+#    #+#             */
/*   Updated: 2022/11/11 17:58:13 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    int i;
    int j;
    char *str;
    
    if (!s1 || !s2)
        return (0);
    str = (char *)ft_calloc((ft_strlen(s1)+ ft_strlen(s2)+1), sizeof(char));
    if (!str)
        return NULL;
    i = -1;
    j = -1;
    while (s1[++i])
        str[++j] = ((char *)s1)[i];
    i = -1;
    while (s2[++i])
        str[++j] = ((char *)s2)[i];
    return (str);
}