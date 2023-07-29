/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/07/29 13:42:49 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> 
#include "init.h"
#include "structs.h"
#include "error.h"
#include "free.h"
#include "threads.h"

int	main(int argc, char **argv)
{
	t_data *data;
	t_philos *philos;
	pthread_mutex_t *forks;
	data = malloc(sizeof(t_data));
	if (!data)
		return (ft_error(EUNKN));
	if (ft_init_parse(argc, argv, data) != 0 )
		return (ft_free_data(data), ft_error(EARGS), 1);
	forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!forks)
		return (ft_free_data(data), ft_error(EUNKN), 1);
	philos = malloc(sizeof(t_philos) * data->num_philo);
		if (!philos)
			return (ft_free_data_mutex(data, forks), ft_error(EUNKN), 1);
	ft_init_philos(philos, data, forks);
	if (ft_create_threads(data, forks, philos) != 0)
		return (ft_free(data, forks, philos), ft_error(ETHRD), 1);
	return(ft_free(data, forks, philos), 0);
}