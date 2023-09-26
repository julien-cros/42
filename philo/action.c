/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:47 by juliencros        #+#    #+#             */
/*   Updated: 2023/09/26 14:27:35 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include "time.h"
#include "ft_print.h"
#include "sleep_think.h"
#include "eat.h"
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

void	*ft_single_philo(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	pthread_mutex_lock(&philos->data->print_mutex);
	printf("[0ms] %d has taken a fork\n", philos->id);
	pthread_mutex_unlock(&philos->data->print_mutex);
	return (NULL);
}

void	*ft_multiple_philos(void *arg)
{
	t_philos	*philos;

	philos = (t_philos *)arg;
	while (pthread_mutex_lock(&philos->data->data_mutex) == 0
		&& !philos->data->is_ready)
		pthread_mutex_unlock(&philos->data->data_mutex);
	pthread_mutex_unlock(&philos->data->data_mutex);
	if (philos->id & 1)
	{
		pthread_mutex_lock(&philos->data->data_mutex);
		usleep(philos->data->time_to_eat * 0.9 + 1);
		pthread_mutex_unlock(&philos->data->data_mutex);
	}
	while (pthread_mutex_lock(&philos->data->data_can_eat_mutex) == 0
		&& !philos->data->is_game_over)
	{
		pthread_mutex_unlock(&philos->data->data_can_eat_mutex);
		ft_eat(philos);
		ft_sleep_think(philos);
	}
	pthread_mutex_unlock(&philos->data->data_can_eat_mutex);
	return (NULL);
}
