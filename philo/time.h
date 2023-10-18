/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:52:39 by codespace         #+#    #+#             */
/*   Updated: 2023/10/18 13:18:54 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "structs.h"

uint64_t	ft_get_unix_time(void);
int			ft_get_time_diff(uint64_t time);
int			ft_get_rounded_time_diff(uint64_t time, int round);

#endif