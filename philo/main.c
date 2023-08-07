/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/08/04 17:42:28 by codespace        ###   ########.fr       */
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

void	ft_init_data(t_data *data);
void	ft_parse_data(t_data *data, int argc, char **argv);
void	ft_init_philos(t_philos *philos, t_data *data, pthread_mutex_t *forks);
// void	ft_print_philos(t_philos *philos, t_data *data);
// void	ft_print_data(t_data *data);

int	main(int argc, char **argv)
{
	t_data data;
	t_philos *philos;
	pthread_mutex_t *forks;

	ft_init_data(&data);
	ft_parse_data(&data, argc, argv);
	philos = malloc(sizeof(t_philos) * data.num_philo);
	if (!philos)
		return (ft_error(EUNKN), 1);
	forks = malloc(sizeof(pthread_mutex_t) * (data.num_philo));
	if (!forks)
		return (ft_free(philos , NULL), ft_error(EUNKN), 1);
	ft_init_philos(philos, &data, forks);
	// ft_print_data(&data);
	// ft_print_philos(philos, &data);
	if (ft_create_threads(&data, philos) == false)
		return (ft_free(philos, forks), ft_error(ETHRD), 1);
	return (ft_free(philos, forks), 0);
}


void	ft_init_data(t_data *data)
{
	data->num_philo = 0;
	data->time_to_die = 0;
	data->time_to_eat = 0;
	data->time_to_sleep = 0;
	data->num_philos_must_eat = 0;
	data->start_time = 0;
	data->is_ready = false;
	data->is_game_over = false;
	// data->data_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	// data->print_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	// data->data_can_eat_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
}


void	ft_parse_data(t_data *data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (ft_error(EARGS), exit(1));
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->num_philos_must_eat = ft_atoi(argv[5]);
	else
		data->num_philos_must_eat = -1;
	if (data->num_philo < 2 || data->time_to_die < 1 // cannot eat if only one philo
		|| data->time_to_eat < 1 || data->time_to_sleep < 1 
		|| (argv[5] && data->num_philos_must_eat < 1))
		return (ft_error(EARGS), exit(1));
}

// void	ft_print_philos(t_philos *philos, t_data *data)
// {
// 	int i;

// 	i = -1;
// 	printf("number of philosophers %d\n\n", data->num_philo);
// 	while (++i < data->num_philo)
// 	{
// 		printf("-----------philo.id[i=%d][id=%d]-----------\n", i,philos[i].id);
// 		printf("philosopher %d\n", philos[i].id);
// 		printf("time left %d\n", philos[i].time_left);
// 		printf("time already eat %d\n", philos[i].time_already_eat);
// 		printf("last meal time %ld\n", philos[i].last_meal_time);
// 		printf("is eating %d\n", philos[i].is_eating);
// 		printf("is sleeping %d\n", philos[i].is_sleeping);
// 		printf("is thinking %d\n", philos[i].is_thinking);
// 		printf("is dead %d\n", philos[i].is_dead);
// 		printf("is ready %d\n", philos[i].is_ready);
// 		printf("number of times each philosopher must eat %d\n", data->num_philos_must_eat);
// 		printf("start time %ld\n", data->start_time);
// 		printf("is ready %d\n", data->is_ready);
// 		printf("is game over %d\n", data->is_game_over);
// 	}
// 	printf("------------------------------\n\n");
// }

// void	ft_print_data(t_data *data)
// {
// 	printf("-----------data-----------\n");
// 	printf("number of philosophers %d\n", data->num_philo);
// 	printf("time to die %ld\n", data->time_to_die);
// 	printf("time to eat %d\n", data->time_to_eat);
// 	printf("time to sleep %ld\n", data->time_to_sleep);
// 	printf("number of times each philosopher must eat %d\n", data->num_philos_must_eat);
// 	printf("start time %ld\n", data->start_time);
// 	printf("is ready %d\n", data->is_ready);
// 	printf("is game over %d\n", data->is_game_over);
// 	printf("------------------------------\n\n");
// }





























	// void	ft_print_philos(t_philos *philos, t_data *data);
	// void	ft_print_data(t_data *data);
	// int		ft_init_data(t_data *data);
	// void	ft_parse_philos(t_philos **philos, t_data *data, pthread_mutex_t *forks);
	// void	ft_parse(t_data *data, pthread_mutex_t *forks, t_philos **philos, char **argv);
	// void	ft_print_philos(t_philos **philos, t_data *data);

	// int i = -1;
	// (void)argc;
	// t_data *data;
	// t_philos **philos;
	// pthread_mutex_t *forks;
	// if (argc < 5 || argc > 6)
	// 	return (ft_error(EARGS), 1);
	// data = malloc(sizeof(t_data));
	// if (!data)
	// 	return (ft_error(EUNKN), 1);
	// forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]-1));
	// if (!forks)
	// 	return (ft_error(EUNKN), ft_free_data(data), 1);
	// philos = malloc(sizeof(t_philos) * ft_atoi(argv[1]-1));
	// if (!philos)
	// 	return (ft_error(EUNKN), ft_free_data_mutex(data, forks), 1);
	// while (philos[++i])
	// 	printf("%d\n", i);
	// ft_init_data(data);
	// ft_parse(data, forks, philos, argv);
	// ft_print_data(data);
	// ft_print_philos(philos, data);
	// return(ft_free(data, forks, philos), 0);

	// t_data *data;
	// t_philos *philos;
	// pthread_mutex_t *forks;
	// data = malloc(sizeof(t_data));
	// if (!data)
	// 	return (ft_error(EUNKN));
	// if (ft_init_parse(argc, argv, data) != 0 )
	// 	return (ft_free_data(data), ft_error(EARGS), 1);
	// forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	// if (!forks)
	// 	return (ft_free_data(data), ft_error(EUNKN), 1);
	// philos = malloc(sizeof(t_philos) * data->num_philo);
	// 	if (!philos)
	// 		return (ft_free_data_mutex(data, forks), ft_error(EUNKN), 1);
	// ft_init_philos(philos, data, forks);
	// if (ft_create_threads(data, forks, philos) != 0)
	// 	return (ft_free(data, forks, philos), ft_error(ETHRD), 1);
	// // ft_print_philos(philos, data);
	// ft_print_data(data);
	// return(ft_free(data, forks, philos), 0);
// }

// void	ft_parse(t_data *data, pthread_mutex_t *forks, t_philos **philos, char **argv)
// {
// 	// (void)forks;
// 	// (void)philos;
// 	data->num_philo = ft_atoi(argv[1]);
// 	data->time_to_die = ft_atoi(argv[2]);
// 	data->time_to_eat = ft_atoi(argv[3]);
// 	data->time_to_sleep = ft_atoi(argv[4]);
// 	if (argv[5])
// 		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
// 	else
// 		data->number_of_times_each_philosopher_must_eat = -1;
// 	data->max_eat = data->number_of_times_each_philosopher_must_eat * data->num_philo;
// 	data->start_time = 0; // je sais pas encore
// 	data->is_ready = false;
// 	data->is_game_over = false;
// 	ft_parse_philos(philos, data, forks);
// }

// void	ft_parse_philos(t_philos **philos, t_data *data, pthread_mutex_t *forks)
// {
// 	int i;

// 	i = -1;
// 	while (++i < data->num_philo-1)
// 	{
// 		printf("i = %d\n", i);
// 		philos[i]->id = i + 1;
// 		philos[i]->time_left = data->time_to_die;
// 		philos[i]->time_already_eat = 0;
// 		philos[i]->last_meal_time = 0;
// 		philos[i]->is_ready = false;
// 		philos[i]->is_eating = false;
// 		philos[i]->is_sleeping = false;
// 		philos[i]->is_thinking = false;
// 		philos[i]->is_dead = false;
// 		// (*philos)[i].data = data;
// 		philos[i]->left_fork = &forks[i];
// 		philos[i]->right_fork = &forks[(i + 1) % data->num_philo];
// 	}
// }

// int	ft_init_data(t_data *data)
// {
// 	data->num_philo = 0;
// 	data->time_to_die = 0;
// 	data->time_to_eat = 0;
// 	data->time_to_sleep = 0;
// 	data->number_of_times_each_philosopher_must_eat = 0;
// 	data->max_eat = 0;
// 	data->start_time = 0;
// 	data->is_ready = false;
// 	data->is_game_over = false;
// 	data->data_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
// 	data->print_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
// 	return (0);
// }
