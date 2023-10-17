/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:13:30 by herbie            #+#    #+#             */
/*   Updated: 2023/10/13 19:56:01 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

# define BUFFER_SIZE 10000

# include "structs.h"
# include "str2.h"
# include "mem.h"
# include <stdlib.h>

char	*ft_itoa(int n);
int		ft_intlen(int n);

#endif /* INT_H */