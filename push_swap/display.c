/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:50:57 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/01 18:54:19 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "strings.h"

int ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (ft_putstr_fd("(null)", fd));
	write(fd, s, ft_strlen(s));
	return (ft_strlen(s));
}
