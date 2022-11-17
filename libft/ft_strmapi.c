/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:31:20 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/17 10:08:06 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i-- > 0)
		str[i] = f(i, s[i]);
	return (str);
}
