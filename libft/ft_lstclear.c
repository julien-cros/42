/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:18:19 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/18 09:46:57 by jcros            ###   ########.fr       */
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
