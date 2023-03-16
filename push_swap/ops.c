/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 23:23:21 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/16 11:27:47 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "display.h"

void	ft_rotate(t_list **list, char *op)
{
	t_list	*last;
	t_list	*tmp;

	last = ft_lstlast(*list);
	tmp = ft_lstnew((*list)->v);
	if (!tmp)
		return ;
	last->n = tmp;
	tmp = (*list)->n;
	free(*list);
	*list = tmp;
	ft_putstr_fd(op, 1);
}

void	ft_push(t_list **src, t_list **dst, char *op)
{
	t_list	*tmp;

	if (!*dst)
	{
		*dst = ft_lstnew((*src)->v);
		if (!*dst)
			return ;
	}
	else
	{
		tmp = ft_lstnew((*src)->v);
		if (!tmp)
			return ;
		ft_lstadd_front(dst, tmp);
	}
	tmp = (*src)->n;
	free(*src);
	*src = tmp;
	ft_putstr_fd(op, 1);
}

void	ft_swap(t_list **list, char *op)
{
	int	tmp;

	tmp = (*list)->v;
	(*list)->v = (*list)->n->v;
	(*list)->n->v = tmp;
	ft_putstr_fd(op, 1);
}

void	ft_reverse_rotate(t_list **list, char *op)
{
	t_list	*last;
	t_list	*second_last;

	second_last = *list;
	last = ft_lstlast(*list);
	ft_lstadd_front(list, ft_lstnew(last->v));
	if (!list)
		return ;
	while (second_last->n->n)
		second_last = second_last->n;
	free(second_last->n);
	second_last->n = NULL;
	ft_putstr_fd(op, 1);
}
