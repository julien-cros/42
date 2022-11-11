/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:50:06 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/11 17:59:06 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (!c)
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return((char *)s + i);
		i--;
	}
	return (0);
}