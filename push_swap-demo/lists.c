/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:43:21 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/20 16:25:19 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include "strings.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *back;

	if (!lst || !new)
		return;
	if (*lst)
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
	else
		*lst = new;
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list *front;

	if (!lst || !new)
		return;
	front = new;
	front->next = *lst;
	*lst = front;
}

void ft_lstclear(t_list **lst, void (*del)(int))
{
	t_list *cpy;
	t_list *nextl;

	if (!lst || !del)
		return;
	nextl = *lst;
	*lst = 0;
	while (nextl)
	{
		cpy = nextl->next;
		ft_lstdelone(nextl, del);
		nextl = cpy;
	}
}

void ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst || !del)
		return;
	(del)(lst->content);
	free(lst);
}

void ft_lstiter(t_list *lst, void (*f)(int))
{
	if (!lst || !f)
		return;
	while (lst != NULL)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}

t_list *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list *ft_lstnew(int content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void ft_list_print(t_list *lst)
{
	if (!lst)
		return;
	while (lst != NULL)
	{
		ft_putnbr_fd(lst->content, 1);
		lst = lst->next;
	}
	// ft_putnbr_fd(*(int *)lst->content, 1);
}
