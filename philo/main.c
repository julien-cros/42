/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/09/26 14:28:44 by juliencros       ###   ########.fr       */
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

static void	ft_init_data(t_data *data);
static void	ft_parse_data(t_data *data, int argc, char **argv);
void		ft_init_philos(t_philos *philos, t_data *data,
				pthread_mutex_t *forks);

int	main(int argc, char **argv)
{
	t_data			data;
	t_philos		*philos;
	pthread_mutex_t	*forks;

	ft_init_data(&data);
	ft_parse_data(&data, argc, argv);
	forks = malloc(sizeof(pthread_mutex_t) * data.num_philo);
	if (!forks)
		return (ft_error(EUNKN), 1);
	philos = malloc(sizeof(t_philos) * data.num_philo);
	if (!philos)
		return (ft_error(EUNKN), 1);
	ft_init_philos(philos, &data, forks);
	if (!ft_create_threads(&data, philos))
		return (ft_error(ETHRD));
	free(forks);
	return (0);
}

static void	ft_init_data(t_data *data)
{
	data->num_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->max_eat = -1;
	data->start_time = 0;
	data->is_ready = false;
	data->is_game_over = false;
}

static void	ft_parse_data(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ft_error(EARGS), exit(1));
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->max_eat = ft_atoi(argv[5]);
	else
		data->max_eat = -1;
	if (data->num_philo < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1 
		|| (argv[5] && data->max_eat < 1))
		return (ft_error(EARGS), exit(1));
}
