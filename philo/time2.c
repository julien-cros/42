/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:18:16 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 13:21:34 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time2.h"
#include "time.h"
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
void	ft_usleep(uint64_t time)
{
	uint64_t	start_time;

	start_time = ft_get_unix_time();
	while ((uint64_t)ft_get_time_diff(start_time) < time)
		usleep(100);
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
