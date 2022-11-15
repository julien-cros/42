/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:31:20 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/15 22:45:23 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    size_t i;
    char *str;

    i = 0;
    if (!s || !f)
        return (0);
    i = ft_strlen(s)+1;
    str = (char *)ft_calloc(i, sizeof(char));
    if (!str)
        return (NULL);
    while (--i > 0)
        str[i] = f(i, str[i]);
    return (str);
}