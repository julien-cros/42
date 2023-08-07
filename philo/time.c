/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:53:27 by codespace         #+#    #+#             */
/*   Updated: 2023/08/04 16:04:35 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long ft_get_time(void)
{
	t_timeval	time;
	unsigned long	time_in_ms;

	gettimeofday(&time, NULL);
	time_in_ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_in_ms);
}

// void	ft_usleep(unsigned long time_in_ms)
// {
// 	unsigned long	start_time;

// 	start_time = ft_get_time();
// 	while (ft_get_time() - start_time < time_in_ms)
// 		usleep(100);
// }

unsigned long	ft_get_time_diff(unsigned long start_time)
{
	return (ft_get_time() - start_time);
}

/**
 * @brief The ft_usleep function sleeps for the specified time in
 * milliseconds.
 *
 * @param time
 */
void	ft_usleep(unsigned long time)
{
	unsigned long	start_time;

	start_time = ft_get_time();
	while ((unsigned long)ft_get_time_diff(start_time) < time)
		usleep(100);
}