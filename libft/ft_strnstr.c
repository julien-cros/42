/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:24:50 by jcros             #+#    #+#             */
/*   Updated: 2022/11/14 10:09:20 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	// size_t	j;

	i = 0;
	// j = 0;
	// if (!*little)
	// 	return((char *)big);
	// while (big[i] && i < len)
	// {
	// 	j = 0;
	// 	if (little[i] == big[j])
	// 	{
	// 		while (big[j + i] && big[j + i] == little[j] && i < len - i - 1)
	// 			j++;
	// 		if (j == len )
	// 			return ((char *)big);
	// 	}
	// 	i++;
	// }
	// return (NULL);

	if (!*little)
		return ((char *)big);
	if (!len)
		return (0);
	while (big[i] && len--)
	{
		if (ft_strncmp(little, big + i, ft_strlen(little)) == 0 && ft_strlen(little) <= len + 1)
			return ((char *)big + i);
		i++;
	}
	return (0);
}
