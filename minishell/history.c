/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:35:47 by codespace         #+#    #+#             */
/*   Updated: 2023/10/13 18:54:56 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	ft_history_new(void)
{
	using_history();
}

void	ft_history_add(char *buffer)
{
	add_history(buffer);
}

void	ft_history_clear(void)
{
	clear_history();
}
