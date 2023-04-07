/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:21:31 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 18:24:07 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRS_H
#define STRS_H

#include <unistd.h>
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
char *ft_strjoin(char const *s, char const c);

#endif