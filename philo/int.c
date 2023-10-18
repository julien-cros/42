/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:01:54 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 13:40:15 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int.h"

/**
 * @brief This function converts a string to an integer.
 * 
 * @param nptr
 * @return int
 */
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res = res + nptr[i] - 48;
		i++;
	}
	return (res *= sign);
}

/**
 * @brief This function checks if a string is a number.
 * 
 * @param str
 * @return t_bool 
 */
bool	ft_isdigit_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (false);
	return (true);
}

/**
 * @brief This function checks if a character is a digit.
 * 
 * @param c
 * @return t_bool 
 */
bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
