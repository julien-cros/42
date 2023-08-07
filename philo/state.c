/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:53:24 by codespace         #+#    #+#             */
/*   Updated: 2023/08/04 18:20:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include <stdio.h>
#include "eat.h"
#include "sleep.h"
#include "time.h"
#include "ft_print.h"

t_bool	ft_check_if_dead(t_philos *philos)
{
	unsigned long end_time;

	pthread_mutex_lock(&philos->data->data_mutex);
	end_time = ft_get_time() - philos->data->start_time;
	pthread_mutex_unlock(&philos->data->data_mutex);
	if (end_time - philos->last_meal_time >= philos->data->time_to_die)
	{
		pthread_mutex_lock(&philos->data->data_mutex);
		philos->data->is_game_over = true;
		philos->is_dead = true;
		pthread_mutex_unlock(&philos->data->data_mutex);
		ft_print(philos, "is_dead", ft_get_time() - philos->data->start_time);
		return (true);
	}
	return (false);
}

t_bool	ft_check_state(t_philos *philos)
{
	if (ft_check_if_dead(philos) == true)
		return (false);
	pthread_mutex_lock(&philos->data->data_mutex);
	if (philos->data->num_philos_must_eat != -1 && (philos->num_philos_has_eaten >= philos->data->num_philos_must_eat))
		return (pthread_mutex_unlock(&philos->data->data_mutex), false);
	pthread_mutex_unlock(&philos->data->data_mutex);
	return (true);
}
