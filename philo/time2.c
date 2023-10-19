/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:18:16 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 19:16:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time2.h"
#include "time.h"
#include "exit.h"
#include "structs.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The ft_usleep function sleeps for the specified time in
 * milliseconds.
 *
 * @param time
 */
void	ft_usleep(uint64_t time, t_data *data)
{
	uint64_t	start_time;

	start_time = ft_get_unix_time();
	while ((uint64_t)ft_get_time_diff(start_time) < time)
	{
		pthread_mutex_lock(&data->meal_mutex);
		if (data->is_game_over)
			return (pthread_mutex_unlock(&data->meal_mutex), (void)0);
		pthread_mutex_unlock(&data->meal_mutex);
		usleep(100);
	}
}

/**
 * @brief The ft_wait_until function waits until the specified time in
 * milliseconds.
 *
 * @param time
 */
void	ft_wait_until(uint64_t time)
{
	while (ft_get_unix_time() < time)
		continue ;
}
