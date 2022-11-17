/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:42:20 by jcros             #+#    #+#             */
/*   Updated: 2022/11/17 10:07:55 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dup;
	size_t	i;

	i = -1;
	if (!s)
		return (0);
	if ((ft_strlen(s) < start))
		return (ft_strdup(""));
	if (ft_strlen(s) < start + len)
		dup = (char *)ft_calloc(ft_strlen(s) - start + 1, sizeof(char));
	else
		dup = (char *)ft_calloc(len + 1, sizeof(char));
	if (!dup)
		return (NULL);
	while (s[++i + start] && i < len)
		dup[i] = s[i + start];
	return (dup);
}
