/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:32:09 by juliencros        #+#    #+#             */
/*   Updated: 2023/06/30 15:09:43 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

#include "pthread.h"

typedef enum e_bool
{
	false,
	true
}t_bool;

typedef struct s_data
{
	int	num_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	max_eat;
	unsigned long start_time;
	t_bool	is_ready;
	t_bool	is_game_over;
	pthread_mutex_t data_mutex;
	pthread_mutex_t	print_mutex;
}t_data;

typedef struct s_philos
{
	pthread_t thread;
	int id;
	int	time_left;
	int time_already_eat;
	unsigned long	last_meal_time;
	t_data	*data;
	pthread_mutex_t *left_fork;
	pthread_mutex_t	*right_fork;
}t_philos;

#endif