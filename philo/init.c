/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/08/04 18:57:17 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "structs.h"
#include "int.h"
#include <stdio.h>
#include <pthread.h>

int	ft_init_parse(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (-1);
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_sleep = ft_atoi(argv[3]);
	if (argc == 6)
		data->num_philos_must_eat = ft_atoi(argv[4]);
	data->start_time = 0;
	data->is_ready = false;
	data->is_game_over = false;
	return (0);
}


void	ft_init_philos(t_philos *philos, t_data *data, pthread_mutex_t *forks)
{
	int i;

	i = -1;
	while (++i < data->num_philo)
	{
		philos[i].thread = 0;
		philos[i].id = i + 1;
		philos[i].time_left = 0;
		philos[i].time_already_eat = 0;
		philos[i].last_meal_time = 0;
		philos[i].data = data;
		philos[i].num_philos_has_eaten = 0;
		philos[i].current_meal_time = 0;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % data->num_philo];
		philos[i].is_ready = false;
		philos[i].is_eating = false;
		philos[i].is_sleeping = false;
		philos[i].is_thinking = false;
		philos[i].is_dead = false;
	}
}

t_bool ft_init_mutex(t_data *data, t_philos *philos)
{
	int i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(philos[i].left_fork, NULL) != 0)
			return (false);
	}
	if (pthread_mutex_init(&data->data_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->data_can_eat_mutex, NULL) != 0)
		return (false);
	return (true);
}