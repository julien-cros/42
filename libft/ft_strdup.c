/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:52:16 by jcros             #+#    #+#             */
/*   Updated: 2022/11/09 13:35:01 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s)
{
    int i;
    char *strdup;

    i = 0;
    strdup = malloc(sizeof(char) * ft_strlen(s) +1 );
    if (!strdup)
        return (NULL);
    while (s[i])
    {
        strdup = s[i];
        i++;
    }
    strdup[i] = '\0';
    return (strdup);
}