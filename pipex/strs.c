/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:00:52 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/13 12:42:47 by juliencros       ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dup;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	dup = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!dup)
		return (0);
	dup[ft_strlen(s1) + ft_strlen(s2)] = 0;
	i = 0;
	while (*s1)
		dup[i++] = *s1++;
	while (*s2)
		dup[i++] = *s2++;
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) < len + start)
		str = (char *)ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = -1;
	while (s[start + ++i] && i < len)
		str[i] = s[start + i];
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}