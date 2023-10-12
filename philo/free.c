/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:40:46 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/12 14:58:35 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"
#include <stdlib.h>
#include <stdio.h>

// void ft_free_data(t_data *data)
// {
// 	free(data);
// }

// void	ft_free_data_mutex(t_data *data, pthread_mutex_t *forks)
// {
// 	ft_free_data(data);
// 	pthread_mutex_destroy(forks);
// 	free(forks);
// }

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

// static void	ft_destroy_threads(t_data *data, t_philo *philos)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < data->philo_count)
// 		pthread_join(philos[i].thread, NULL);
// 	i = -1;
// 	while (++i < data->philo_count)
// 		pthread_mutex_destroy(philos[i].left_fork);
// 	pthread_mutex_destroy(&data->data_mutex);
// 	pthread_mutex_destroy(&data->meal_mutex);
// 	pthread_mutex_destroy(&data->print_mutex);
// }
