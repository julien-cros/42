/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/23 13:38:23 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h> 
#include "init.h"
#include "structs.h"
#include "error.h"
#include "init.h"
#include "int.h"
#include "threads.h"
#include "parse.h"

int	main(int argc, char *argv[])
{
	t_data			data;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	ft_init_data(&data);
	if (!ft_parse_args(argc, argv, &data))
		return (ft_err(EARGS));
	forks = malloc(sizeof(pthread_mutex_t) * data.philo_count);
	if (!forks)
		return (ft_err(EUNKN));
	philos = malloc(sizeof(t_philo) * data.philo_count);
	if (!philos)
		return (free(forks), ft_err(EUNKN));
	ft_init_philos(philos, &data, forks);
	if (!ft_spawn_threads(&data, philos))
		return (free(philos), 	free(forks), ft_err(ETHRD));
	free(forks);
	free(philos);
	return (0);
}
