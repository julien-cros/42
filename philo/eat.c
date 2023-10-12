/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:06:29 by codespace         #+#    #+#             */
/*   Updated: 2023/10/12 14:59:00 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eat.h"
#include <stdio.h>
#include "time.h"
#include "free.h"
#include "ft_print.h"
#include <unistd.h>

// void	ft_eat(t_philos *philos)
// {
// 	int	eat_time;

// 	pthread_mutex_lock(&philos->data->data_mutex);
// 	eat_time = philos->data->time_to_eat;
// 	pthread_mutex_unlock(&philos->data->data_mutex);
// 	if (philos->id & 1)
// 		pthread_mutex_lock(philos->right_fork);
// 	else
// 		pthread_mutex_lock(philos->left_fork);
// 	ft_print(philos, "has taken a fork", eat_time);
// 	if (philos->id & 1)
// 		pthread_mutex_lock(philos->left_fork);
// 	else
// 		pthread_mutex_lock(philos->right_fork);
// 	ft_print(philos, "has taken a fork", eat_time);
// 	ft_print(philos, "is eating", eat_time);
// 	pthread_mutex_lock(&philos->data->data_can_eat_mutex);
// 	philos->last_meal_time = ft_get_time_in_ms();
// 	philos->eat_count++;
// 	pthread_mutex_unlock(&philos->data->data_can_eat_mutex);
// 	ft_usleep(eat_time);
// 	pthread_mutex_unlock(philos->left_fork);
// 	pthread_mutex_unlock(philos->right_fork);
// }
