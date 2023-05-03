/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:00:00 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/03 19:35:55 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

#endif