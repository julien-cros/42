/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:03:20 by juliencros        #+#    #+#             */
/*   Updated: 2023/09/26 14:28:23 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include <stdio.h>
#include <pthread.h>
#include "error.h"
#include "init.h"
#include "free.h"
#include "time.h"
#include <sys/time.h>
#include <unistd.h>
#include "ft_print.h"
#include "action.h"
#include "exit.h"

static void		*ft_redirect_philos(void *arg);
static t_bool	ft_init_mutexes(t_data *data, t_philos *philos);

t_bool	ft_create_threads(t_data *data, t_philos *philos)
{
	int	i;

	if (!ft_init_mutexes(data, philos))
		return (false);
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_create(&philos[i].thread, NULL,
				&ft_redirect_philos, &philos[i]))
			return (false);
	}
	pthread_mutex_lock(&data->data_mutex);
	data->start_time = ft_get_time_in_ms();
	i = -1;
	while (++i < data->num_philo)
		philos[i].last_meal_time = data->start_time;
	data->is_ready = true;
	pthread_mutex_unlock(&data->data_mutex);
	ft_wait_for_exit(data, philos);
	ft_destroy_threads(data, philos);
	return (true);
}

static void	*ft_redirect_philos(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	if (philo->data->num_philo == 1)
		ft_single_philo(philo);
	else
		ft_multiple_philos(philo);
	return (NULL);
}

static t_bool	ft_init_mutexes(t_data *data, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(philos[i].left_fork, NULL) != 0)
			return (false);
	}
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->data_can_eat_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (false);
	return (true);
}
