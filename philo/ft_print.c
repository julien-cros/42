/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:47:24 by codespace         #+#    #+#             */
/*   Updated: 2023/09/26 14:30:40 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "time.h"
#include <stdio.h>

void	ft_print(t_philos *philos, char *str, long int time)
{
	pthread_mutex_lock(&philos->data->data_can_eat_mutex);
	if (!philos->data->is_game_over)
	{
		pthread_mutex_lock(&philos->data->print_mutex);
		printf("[%dms] %d %s\n", ft_get_rounded_time_diff(
				philos->data->start_time, time), philos->id, str);
		pthread_mutex_unlock(&philos->data->print_mutex);
	}
	pthread_mutex_unlock(&philos->data->data_can_eat_mutex);
}
