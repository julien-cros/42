/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:53:27 by codespace         #+#    #+#             */
/*   Updated: 2023/09/25 11:04:59 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

unsigned long	ft_get_time_in_ms(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return ((unsigned long)(time.tv_sec * 1000 + time.tv_usec / 1000));
}

/**
 * @brief The ft_get_time_diff function returns the difference between
 * the current time and the time passed in milliseconds.
 * 
 * @param time
 * @return int 
 */
int	ft_get_time_diff(unsigned long time)
{
	unsigned long	current_time;

	current_time = ft_get_time_in_ms();
	return ((int)(current_time - time));
}

/**
 * @brief The ft_get_rounded_time_diff function returns the difference
 * between the current time and the time passed in milliseconds rounded
 * to the nearest multiple of the round parameter.
 * 
 * @param time 
 * @param round 
 * @return int 
 */
int	ft_get_rounded_time_diff(unsigned long time, int round)
{
	unsigned long	current_time;

	current_time = ft_get_time_in_ms();
	return ((int)(current_time - time) - ((int)(current_time - time) % round));
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

	start_time = ft_get_time_in_ms();
	while ((unsigned long)ft_get_time_diff(start_time) < time)
		usleep(100);
}
