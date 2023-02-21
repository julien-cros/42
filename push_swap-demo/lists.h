/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:55:08 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/20 16:25:15 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

typedef struct s_list
{
	int content;
	struct s_list *next;
} t_list;

void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
void ft_lstclear(t_list **lst, void (*del)(int));
void ft_lstdelone(t_list *lst, void (*del)(int));
void ft_lstiter(t_list *lst, void (*f)(int));
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstnew(int content);
int ft_lstsize(t_list *lst);
void ft_list_print(t_list *lst);

#endif