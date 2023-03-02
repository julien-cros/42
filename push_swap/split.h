/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:00:53 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/01 22:19:24 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
#define SPLIT_H

#include <stdlib.h>

char **ft_split(char const *s, char c);
void ft_free(char **list, size_t idx);

#endif
