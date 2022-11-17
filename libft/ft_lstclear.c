/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:18:19 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/17 22:09:22 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cpy;
	t_list	*nextl;

	if (!lst || !del)
		return ;
	nextl = *lst;
	*lst = 0;
	while (nextl)
	{
		cpy = nextl->next;
		ft_lstdelone(nextl, del);
		nextl = cpy;
	}
}
