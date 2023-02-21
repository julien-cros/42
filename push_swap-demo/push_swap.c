/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 14:51:35 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/20 17:06:16 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "stdio.h"
#include "strings.h"

int main(int argc, char **argv)
{
	int i;
	t_list *list;

	if (argc < 1)
		return (0);
	list = ft_lstnew(ft_atoi(argv[1]));
	if (!list)
		return (0);
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(&list, ft_lstnew(ft_atoi(argv[i++])));

		printf("i=%d\n", i);
	}
	ft_list_print(list);
	return (1);
}