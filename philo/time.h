/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:52:39 by codespace         #+#    #+#             */
/*   Updated: 2023/10/21 11:41:08 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "structs.h"

uint64_t	ft_get_unix_time(void);
int			ft_get_time_diff(uint64_t time);
void		ft_usleep(uint64_t time, t_data *data);

#endif