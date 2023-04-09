/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:27:59 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/09 13:55:21 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "strs.h"

int ft_strchr(char *s, char **base)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !*base)
		return (1);
	while (i < ft_strlen(base[k]))
	{
		if (i+1 == ft_strlen(base[k]) && base[k+1])
		{
			k++;
			i = 0;
		}
		j = 0;
		if (base[k][i] == s[j])
		{
			while (base[k][i] == s[j])
			{
				i++;
				j++;
			}
		if (j == ft_strlen(s))
			return (0);
		}
		i++;
	}
	return (1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	return ((void)ft_memset(s, 0, n));
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = s;
	while (i < n)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

