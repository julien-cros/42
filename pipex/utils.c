/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:27:59 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/03 17:07:39 by juliencros       ###   ########.fr       */
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
