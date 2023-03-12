/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:45:27 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/03 13:33:14 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrays.h"

void ft_sort_array(int **arr, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*arr)[i] > (*arr)[j])
			{
				tmp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}