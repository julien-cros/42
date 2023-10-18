/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 15:10:13 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "structs.h"
#include "int.h"
#include <stdio.h>
#include <pthread.h>

/**
 * @brief The ft_init_philos function initializes the philos struct with the
 * correct start values.
 * 
 * @param philos 
 * @param data 
 * @param forks 
 */
void	ft_init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < data->philo_count)
	{
		philos[i].id = i + 1;
		philos[i].eat_count = 0;
		philos[i].data = data;
		philos[i].last_meal_time = 0;
		philos[i].start_time = 0;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % data->philo_count];
	}
}

/**
 * @brief The ft_init_data function initializes the data struct with the
 * correct values.
 * 
 * @param data 
 */
void	ft_init_data(t_data *data)
{
	data->philo_count = 0;
	data->time_die_in_ms = 0;
	data->time_eat_in_ms = 0;
	data->time_sleep_in_ms = 0;
	data->max_eat = -1;
	data->start_time = 0;
	data->is_game_over = false;
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
t_bool	ft_init_mutexes(t_data *data, t_philo *philos)
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
