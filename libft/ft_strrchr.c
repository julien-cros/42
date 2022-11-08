/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:50:06 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/08 18:57:03 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (!c)
		return (s + i);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return(s + i);
		i--;
	}
	return (0);
}