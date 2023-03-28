/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:27:59 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/27 17:30:43 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);

int ft_strchr(char *s, char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s || !base)
		return (1);
	while (i < ft_strlen(base))
	{
		j = 0;
		if (base[i] == s[j])
		{
			while (base[i] == s[j])
			{
				i++;
				j++;
			}
		if (j == ft_strlen(s))
			return (0);
		}
		printf("%d\n", j);
		i++;
	}
	return (1);
}


size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (i[s])
		++i;
	return (i);
}
