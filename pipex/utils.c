/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:27:59 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:49:08 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "utils.h"
#include "strs.h"
#include "mem.h"

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
