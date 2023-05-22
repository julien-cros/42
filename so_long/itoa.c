/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:36:10 by codespace         #+#    #+#             */
/*   Updated: 2023/05/22 18:36:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

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
