/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:32:09 by juliencros        #+#    #+#             */
/*   Updated: 2023/09/26 14:23:52 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "pthread.h"
# include <sys/time.h>

typedef struct timeval	t_timeval;

typedef enum e_bool
{
	false,
	true
}t_bool;

typedef struct s_data
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	unsigned long	start_time;
	t_bool			is_ready;
	t_bool			is_game_over;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	data_can_eat_mutex;
}t_data;

typedef struct s_philos
{
	pthread_t		thread;
	int				id;
	int				eat_count;
	unsigned long	last_meal_time;
	int				num_philos_has_eaten;
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}t_philos;

#endif