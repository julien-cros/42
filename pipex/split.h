/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:50:57 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/09 14:27:24 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
#define SPLIT_H

#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include "utils.h"
#include "strs.h"

char	**ft_split(char const *s, char c);

#endif