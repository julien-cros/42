/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:05:04 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/11 22:01:49 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int word_count(const char *str, char sep)
{
    size_t i;
    size_t count;

    i = -1;
    count = 0;
    while (str[++i])
    {
        if(str[i] == sep)
            count++;
    }
    return (count);
}

char fill_split(char **split, char const *str, char sep)
{
    size_t i;
    size_t j;
    size_t k;

    i = -1;
    j = -1;
    k = 0;
    while (str[i])
    {    
        j = -1;
        while (str[i] != sep)
        {
           split[k][++j] = str[i];
           i++;
        }
        if(str[i] == sep)
            k++;
        i++;
    }
    return(**split);
}

char **ft_split(char const *str, char sep)
{
    size_t count;
    char **split;
    char **final_split;

    if (!str)
        return (0);
    while(*str == sep)
        str++;
    count = word_count(str, sep);
    *split = (char *)ft_calloc(count, sizeof(char));
    if (!split)
        return NULL;
    **final_split = fill_split(split, str, sep);
    return (final_split);
}
// faire ++str si pas 