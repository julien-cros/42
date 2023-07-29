/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/07/01 23:14:30 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "structs.h"
#include "int.h"
#include <stdio.h>

int	ft_init_parse(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (-1);
	data->num_philo = ft_atoi(argv[0]);
	data->time_to_die = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	if (argc == 4)
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[3]);
	data->max_eat = 0;
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
		philos[i].left_fork = &forks[i + 1];
		philos[i].right_fork = &forks[(i + 1)% data->num_philo];
	}
}