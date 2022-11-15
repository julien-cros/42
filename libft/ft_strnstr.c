/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:24:50 by jcros             #+#    #+#             */
/*   Updated: 2022/11/15 17:07:57 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	
	i = 0;

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

// int main()
// {
//     char big[] = "aaacabcd";
//     char little[] = "abcd";

//     printf("%s", ft_strnstr(big, little, 9));
// }