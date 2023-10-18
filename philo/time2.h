/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:17:54 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 13:19:48 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME2_H
# define TIME2_H

# include "structs.h"

void	ft_usleep(uint64_t time);
void	ft_wait_until(uint64_t time);

#endif