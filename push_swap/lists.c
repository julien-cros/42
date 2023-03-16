/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:17:41 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/16 11:43:07 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "display.h"
#include "strings.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->v = content;
	new->n = 0;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*head;

	head = *lst;
	if (!lst || !new)
		return ;
	new->n = head;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->n = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst && lst->n)
		lst = lst->n;
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*head;
	t_list	*tmp;

	if (!lst)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head->n;
		free(head);
		head = tmp;
	}
	*lst = NULL;
}
