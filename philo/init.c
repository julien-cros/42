/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 13:35:38 by juliencros       ###   ########.fr       */
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
