/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:17:54 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 14:35:33 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME2_H
# define TIME2_H

# include "structs.h"

void	ft_usleep(uint64_t time, t_data *data);
void	ft_wait_until(uint64_t time);

#endif