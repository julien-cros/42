/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 14:31:49 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/23 14:32:05 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrays.h"
#include "lists.h"

void	ft_sort_int_array(int **arr, int size)
{
	int	i;
	int	j;
	int	tmp;

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

t_list	*ft_fill_list_with_args(int *args, int size)
{
	t_list	*list;
	int		i;

	i = 1;
	list = ft_lstnew(args[0]);
	while (i < size)
	{
		ft_lstadd_back(&list, ft_lstnew(args[i]));
		i++;
	}
	return (list);
}