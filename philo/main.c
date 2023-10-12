/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/12 14:57:28 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> 
#include "init.h"
#include "structs.h"
#include "error.h"
#include "free.h"
#include "int.h"
#include "threads.h"

void	ft_init_philos(t_philo *philos, t_data *data, pthread_mutex_t *forks);
void	ft_init_data(t_data *data);
t_bool	ft_parse_args(int argc, char **argv, t_data *data);
				
int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	ft_init_data(&data);
	if (!ft_parse_args(argc, argv, &data))
		return (ft_err(EARGS));
	forks = malloc(sizeof(pthread_mutex_t) * data.philo_count);
	if (!forks)
		return (ft_err(EUNKN), 1);
	philos = malloc(sizeof(t_philo) * data.philo_count);
	if (!philos)
		return (ft_err(EUNKN), 1);
	ft_init_philos(philos, &data, forks);
	if (!ft_spawn_threads(&data, philos))
		return (ft_err(ETHRD));
	free(forks);
	return (0);
}

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

t_bool	ft_parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
		return (false);
	data->philo_count = ft_atoi(argv[1]);
	data->time_die_in_ms = ft_atoi(argv[2]);
	data->time_eat_in_ms = ft_atoi(argv[3]);
	data->time_sleep_in_ms = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	if (data->philo_count < 1 || data->time_die_in_ms < 1
		|| data->time_eat_in_ms < 1 || data->time_sleep_in_ms < 1
		|| (argc == 6 && data->max_eat < 1))
		return (false);
	return (true);
}
