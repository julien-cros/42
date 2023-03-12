/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:17:47 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/12 09:46:11 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

typedef struct s_list
{
	int v;
	struct s_list *n;
} t_list;

t_list *ft_lstnew(int content);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
void ft_lstclear(t_list **lst);

#endif