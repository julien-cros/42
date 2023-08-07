/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:07:13 by codespace         #+#    #+#             */
/*   Updated: 2023/08/04 18:21:55 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sleep.h"
#include <stdio.h>
#include "time.h"
#include "ft_print.h"
#include <unistd.h>

void	ft_is_sleeping(t_philos *philos)
{
	int sleep_in_ms;

	pthread_mutex_lock(&philos->data->data_mutex);
	sleep_in_ms = ft_get_time() - philos->data->start_time;
	pthread_mutex_unlock(&philos->data->data_mutex);
	ft_print(philos, "is sleeping", sleep_in_ms);
	ft_usleep(philos->data->time_to_sleep);
	ft_print(philos, "is thinking", ft_get_time() - philos->data->start_time);
}
