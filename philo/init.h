/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:52 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 15:10:06 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "structs.h"
# include "pthread.h"

void	ft_init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks);
void	ft_init_data(t_data *data);
t_bool	ft_init_mutexes(t_data *data, t_philo *philos);

#endif
