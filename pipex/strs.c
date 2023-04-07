/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:00:52 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 18:23:56 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strs.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (i[s])
		++i;
	return (i);
}

char *ft_strjoin(char const *s, char const c)
{
	char *dup;
	size_t i;
	if (!s || !c)
		return (0);
	dup = (char *)malloc((ft_strlen(s) + 2) * sizeof(char));
	if (!dup)
		return (0);
	dup[ft_strlen(s) + 1] = 0;
	i = ft_strlcpy(dup, s, ft_strlen(s) + 1);
	dup[i++] = c;
	dup[i++] = '\0';
	return (dup);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = -1;
	if (size == 0)
		return (ft_strlen(src));
	while (src[++i] && i < size - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

