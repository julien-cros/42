/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:23:28 by jcros             #+#    #+#             */
/*   Updated: 2023/05/11 13:31:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

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

char	*ft_strndup(const char *s, size_t n)
{
	size_t		i;
	char	*dup;

	i = 0;
	dup = (char *)ft_calloc((n + 1), sizeof(char));
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	size_n(int n)
{
	int				count;
	unsigned int	cpy;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	cpy = n;
	while (cpy)
	{
		cpy /= 10;
		count++;
	}
	return (count);
}

char	*fill_str(char *str, int n)
{
	int				i;
	unsigned int	cpy;

	i = size_n(n) - 1;
	if (n < 0)
		n *= -1;
	cpy = n;
	while (cpy > 0)
	{
		str[i] = cpy % 10 + 48;
		cpy /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == 0)
		return (ft_strdup("0"));
	len = size_n(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str = fill_str(str, n);
	return (str);
}

int ft_find_p(char **strs, t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (strs[i][j])
	{
		if (strs[i][j] == 'P')
		{
			map->start_col_pos = i;
			map->start_raw_pos = j;
			return (0);
		}
		j++;
		if (strs[i][j] == '\n')
		{
			i++;
			j = 0;
		}
	}
	return (-1);
}