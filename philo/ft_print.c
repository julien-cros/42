/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:47:24 by codespace         #+#    #+#             */
/*   Updated: 2023/10/19 19:41:41 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include "time.h"
#include <stdio.h>

/**
 * @brief The ft_print function prints the message.
 *
 * @param philo
 * @param msg
 */
void	ft_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->meal_mutex);
	if (!philo->data->is_game_over)
	{
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%d %d %s\n",
			ft_get_time_diff(philo->data->start_time),
			philo->id, msg);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
}
