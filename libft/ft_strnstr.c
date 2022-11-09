/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:24:50 by jcros             #+#    #+#             */
/*   Updated: 2022/11/09 12:38:43 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *little, const char *big, size_t len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!little)
		return((char *)big);
	while (((char *)little)[i] && i < len - 1)
	{
		if (((char *)little)[i] == ((char *)big)[j])
		{
			while (((char *)big)[j] && ((char *)big)[j] == ((char *)little)[i + j] && i < len - i - 1)
			{
				j++;
			}
			if (j == len)
				return ((char *)big)[i];
		}
		i++;
		j = 0;
	}
	return (0);
}