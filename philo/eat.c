/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:06:29 by codespace         #+#    #+#             */
/*   Updated: 2023/10/18 13:37:31 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eat.h"
#include <stdio.h>
#include "time.h"
#include "time2.h"
#include "free.h"
#include "ft_print.h"
#include <unistd.h>

/**
 * @brief The ft_eat function locks the forks, eats and unlocks the forks.
 *
 * @param philo
 */
void	ft_eat(t_philo *philo)
{
	int	eat_time;

	pthread_mutex_lock(&philo->data->data_mutex);
	eat_time = philo->data->time_eat_in_ms;
	pthread_mutex_unlock(&philo->data->data_mutex);
	if (philo->id & 1)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork", eat_time);
	if (philo->id & 1)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken a fork", eat_time);
	ft_print(philo, "is eating", eat_time);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = ft_get_unix_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	ft_usleep(eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
