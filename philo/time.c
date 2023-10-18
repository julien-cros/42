/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:53:27 by codespace         #+#    #+#             */
/*   Updated: 2023/10/18 13:18:11 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief The ft_get_unix_time function returns the current time in
 * milliseconds.
 * 
 * @return uint64_t 
 */
uint64_t	ft_get_unix_time(void)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000));
}

/**
 * @brief The ft_get_time_diff function returns the difference between
 * the current time and the time passed in milliseconds.
 * 
 * @param time
 * @return int 
 */
int	ft_get_time_diff(uint64_t time)
{
	uint64_t	current_time;

	current_time = ft_get_unix_time();
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
int	ft_get_rounded_time_diff(uint64_t time, int round)
{
	uint64_t	current_time;

	current_time = ft_get_unix_time();
	return ((int)(((current_time - time) / round) * round));
}
