/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:07:13 by codespace         #+#    #+#             */
/*   Updated: 2023/10/19 20:19:07 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sleep_think.h"
#include "time.h"
#include "ft_print.h"
#include <unistd.h>

/**
 * @brief The ft_sleep_and_think function sleeps and thinks.
 *
 * @param philo
 */
void	ft_sleep_and_think(t_philo *philo)
{
	int	sleep_time;

	pthread_mutex_lock(&philo->data->data_mutex);
	sleep_time = philo->data->time_sleep_in_ms;
	pthread_mutex_unlock(&philo->data->data_mutex);
	ft_print(philo, "is sleeping");
	ft_usleep(sleep_time, philo->data);
	ft_print(philo, "is thinking");
	ft_usleep(philo->data->time_eat_in_ms, philo->data);
}
