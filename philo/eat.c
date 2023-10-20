/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:06:29 by codespace         #+#    #+#             */
/*   Updated: 2023/10/20 18:48:09 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eat.h"
#include <stdio.h>
#include "time.h"
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
	if (philo->id % 2)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork");
	if (philo->id % 2)
		pthread_mutex_lock(philo->left_fork);
	else
		pthread_mutex_lock(philo->right_fork);
	ft_print(philo, "has taken a fork");
	ft_print(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_time = ft_get_unix_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	ft_usleep(eat_time, philo->data);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
