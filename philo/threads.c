/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:03:20 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/12 14:55:09 by juliencros       ###   ########.fr       */
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


static void		*ft_redirect_philo(void *arg);
static t_bool	ft_init_mutexes(t_data *data, t_philo *philos);
static void		ft_destroy_threads(t_data *data, t_philo *philos);

/**
 * @brief The ft_spawn_threads function creates the threads and initializes
 * the mutexes. It also sets the start time and the last meal time for each
 * philo. When the threads are created, it sets the is_ready flag to true, 
 * which allows the threads to start.
 * 
 * @param data 
 * @param philos 
 * @return t_bool 
 */
t_bool	ft_spawn_threads(t_data *data, t_philo *philos)
{
	int	i;

	if (!ft_init_mutexes(data, philos))
		return (false);
	pthread_mutex_lock(&data->data_mutex);
	data->start_time = ft_get_unix_time();
	pthread_mutex_unlock(&data->data_mutex);
	i = -1;
	while (++i < data->philo_count)
	{
		pthread_mutex_lock(&data->data_mutex);
		philos[i].start_time = ft_get_unix_time();
		philos[i].last_meal_time = ft_get_unix_time();
		pthread_mutex_unlock(&data->data_mutex);
		if (pthread_create(&philos[i].thread, NULL,
				&ft_redirect_philo, &philos[i]))
			return (false);
	}
	ft_wait_for_exit(data, philos);
	ft_destroy_threads(data, philos);
	return (true);
}

/**
 * @brief The ft_redirect_philo function is the function that is called by the
 * threads. It calls the ft_single_philo function if there is only one
 * philosopher, otherwise it calls the ft_multiple_philos function.
 * 
 * @param arg 
 * @return void* 
 */
static void	*ft_redirect_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
		ft_single_philo(philo);
	else
		ft_multiple_philos(philo);
	return (NULL);
}

/**
 * @brief The ft_init_mutexes function initializes the mutexes for the forks,
 * the data, the meal and the print. It returns false if any of the mutexes
 * fail to initialize.
 * 
 * @param data 
 * @param philos 
 * @return t_bool 
 */
static t_bool	ft_init_mutexes(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		if (pthread_mutex_init(philos[i].left_fork, NULL) != 0)
			return (false);
	}
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->meal_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (false);
	return (true);
}

/**
 * @brief The ft_destroy_threads function destroys the threads and the mutexes.
 * 
 * @param data 
 * @param philos 
 */
static void	ft_destroy_threads(t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
		pthread_join(philos[i].thread, NULL);
	i = -1;
	while (++i < data->philo_count)
		pthread_mutex_destroy(philos[i].left_fork);
	pthread_mutex_destroy(&data->data_mutex);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
}
