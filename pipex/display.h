/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:11:57 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/19 21:48:55 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
#define DISPLAY_H


#include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_puchar_fd(char c, int fd);


#endif