/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:07:13 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 14:26:53 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sleep_think.h"
#include <stdio.h>
#include "time.h"
#include "ft_print.h"
#include <unistd.h>

void	ft_sleep_think(t_philos *philos)
{
	int	sleep_time;

	pthread_mutex_lock(&philos->data->data_mutex);
	sleep_time = philos->data->time_to_sleep;
	pthread_mutex_unlock(&philos->data->data_mutex);
	ft_print(philos, "is sleeping", sleep_time);
	ft_usleep(sleep_time);
	ft_print(philos, "is thinking", sleep_time);
}
