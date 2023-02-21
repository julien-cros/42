/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:01:05 by juliencros        #+#    #+#             */
/*   Updated: 2023/02/18 18:49:58 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
# define STRINGS_H

#include "stdlib.h"
#include "unistd.h"

int ft_atoi(const char *nptr);
void ft_putnbr_fd(int n, int fd);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);

#endif