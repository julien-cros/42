/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:52:39 by codespace         #+#    #+#             */
/*   Updated: 2023/09/25 11:05:10 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "structs.h"

unsigned long	ft_get_time_in_ms(void);
int				ft_get_time_diff(unsigned long time);
int				ft_get_rounded_time_diff(unsigned long time, int round);
void			ft_usleep(unsigned long time);

#endif