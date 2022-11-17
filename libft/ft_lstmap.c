/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:42:21 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/18 00:24:18 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	//t_list	*cpy;
	t_list	*start;

	if (!lst || !f || !del)
		return (NULL);
	//cpy = lst;
	//ft_lstclear(&lst, del);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	new_lst = start;
	//cpy = cpy->next;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst)
			return (NULL);
		new_lst = new_lst->next;
		lst = lst->next;
		//free(lst);
	}
	new_lst->next = NULL;
	ft_lstclear(&lst, del);
	return (start);
}
