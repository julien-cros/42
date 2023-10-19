/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:32:09 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/19 08:39:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdint.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct timeval	t_timeval;

typedef struct s_data
{
	int				philo_count;
	int				time_die_in_ms;
	int				time_eat_in_ms;
	int				time_sleep_in_ms;
	int				max_eat;
	uint64_t		start_time;
	t_bool			is_ready;
	t_bool			is_game_over;
	pthread_mutex_t	data_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	print_mutex;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	uint64_t		last_meal_time;
	uint64_t		start_time;
	t_data			*data;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

#endif /* STRUCTS_H */