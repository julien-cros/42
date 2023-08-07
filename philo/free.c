/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:40:46 by juliencros        #+#    #+#             */
/*   Updated: 2023/08/04 17:16:10 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include <stdlib.h>
#include <stdio.h>

void ft_free_data(t_data *data)
{
	free(data);
}

void	ft_free_data_mutex(t_data *data, pthread_mutex_t *forks)
{
	ft_free_data(data);
	pthread_mutex_destroy(forks);
	free(forks);
}

// void ft_free(t_data *data, pthread_mutex_t *forks, t_philos **philos)
// {
// 	int i;

// 	i = -1;
// 	if (forks)
// 		{
// 			pthread_mutex_destroy(forks);
// 			free(forks);
// 		}
// 	if ((*philos))
// 	{
// 		while (++i < data->num_philo-1)
// 			free(philos[i]);
// 	}
// 	if (data)
// 		free(data);

// }

void ft_free(t_philos *philos, pthread_mutex_t *forks)
{
	if (forks)
	{
		free(forks);
	}
	(void)forks;
	if (philos)
		free(philos);
}

void	ft_close_threads(t_data *data, t_philos *philos)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		pthread_join(philos[i].thread, NULL);
	}
	i = -1;
	while (++i < 0)
	{
		pthread_mutex_destroy(philos[i].left_fork);
	}
		ft_free_mutex(philos->data);
}

void	ft_free_mutex(t_data *data)
{
	pthread_mutex_destroy(&data->data_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->data_can_eat_mutex);
}