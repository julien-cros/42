/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:53:47 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 14:58:16 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action.h"
#include "structs.h"
#include "time.h"
#include "ft_print.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>

/**
 * @brief The ft_single_philo function is used when there is only one
 * philosopher. It is used to print the first message.
 *
 * @param arg
 * @return void*
 */
void	*ft_single_philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->print_mutex);
	printf("[0ms] %d has taken a fork\n", philo->id);
	pthread_mutex_unlock(&philo->data->print_mutex);
	return (NULL);
}

/**
 * @brief The ft_multiple_philos function waits for the start of the game,
 * then the odd philosophers wait for the even ones to eat, and then they
 * start their cycle.
 *
 * @param arg
 * @return void*
 */
void	*ft_multiple_philos(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->data_mutex);
	philo->start_time = ft_get_unix_time();
	philo->last_meal_time = ft_get_unix_time();
	pthread_mutex_unlock(&philo->data->data_mutex);
	if (philo->id & 1)
	{
		pthread_mutex_lock(&philo->data->data_mutex);
		usleep(1);
		pthread_mutex_unlock(&philo->data->data_mutex);
	}
	while (pthread_mutex_lock(&philo->data->meal_mutex) == 0
		&& !philo->data->is_game_over)
	{
		pthread_mutex_unlock(&philo->data->meal_mutex);
		ft_eat(philo);
		ft_sleep_and_think(philo);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (NULL);
}
