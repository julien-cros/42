/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:40:46 by juliencros        #+#    #+#             */
/*   Updated: 2023/07/01 14:44:57 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include <stdlib.h>

void ft_free_data(t_data *data)
{
	free(data);
}

void	ft_free_data_mutex(t_data *data, pthread_mutex_t *forks)
{
	ft_free_data(data);
	// pthread_mutex_destroy(&mutex);
	free(forks);
}

void ft_free(t_data *data, pthread_mutex_t *forks, t_philos *philos)
{
	int i;

	i = -1;
	if (forks)
		free(forks);
	if (philos)
	{
		while (++i < data->num_philo)
		{
			free(philos[i].data);
			free(philos);
		}
	}
	if (data)
		free(data);
}
