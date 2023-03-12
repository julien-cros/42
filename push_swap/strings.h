/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:52:38 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/02 17:59:11 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>

size_t ft_strlen(const char *s);
long ft_atoi(const char *nptr);
void *ft_calloc(size_t nmemb, size_t size);
void *ft_memset(void *s, int c, size_t n);
char *ft_substr(char const *s, unsigned int start, size_t len);
void ft_putnbr_fd(int n, int fd);

#endif