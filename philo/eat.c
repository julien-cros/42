/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:06:29 by codespace         #+#    #+#             */
/*   Updated: 2023/08/04 18:16:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eat.h"
#include <stdio.h>
#include "time.h"
#include "free.h"
#include "ft_print.h"
#include <unistd.h>

void	ft_is_eating(t_philos *philos)
{
	int eat_in_ms;

	pthread_mutex_lock(&philos->data->data_mutex);
	eat_in_ms = ft_get_time() - philos->data->start_time;
	pthread_mutex_unlock(&philos->data->data_mutex);
	if (philos->id & 1)
		pthread_mutex_lock(philos->right_fork);
	else
		pthread_mutex_lock(philos->left_fork);
	ft_print(philos, "has taken a fork", eat_in_ms);
	if (philos->id & 1)
		pthread_mutex_lock(philos->left_fork);
	else
		pthread_mutex_lock(philos->right_fork);
	ft_print(philos, "has taken a fork", eat_in_ms);
	ft_print(philos, "is eating", eat_in_ms);
	pthread_mutex_lock(&philos->data->data_can_eat_mutex);
	philos->num_philos_has_eaten++;
	philos->last_meal_time = ft_get_time() - philos->data->start_time;
	pthread_mutex_unlock(&philos->data->data_can_eat_mutex);
	ft_usleep(philos->data->time_to_eat);
	pthread_mutex_unlock(philos->right_fork);
	pthread_mutex_unlock(philos->left_fork);
	}
