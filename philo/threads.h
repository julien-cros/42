/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:59:46 by juliencros        #+#    #+#             */
/*   Updated: 2023/08/04 17:42:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "structs.h"

// int ft_create_threads(t_data *data, pthread_mutex_t *forks, t_philos *philos);

// t_bool	ft_create_philos(t_data *data, t_philos *philos);
void	*ft_philo(void *arg);
t_bool	ft_create_threads(t_data *data, t_philos *philos);

#endif