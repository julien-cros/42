/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:52:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/20 19:47:53 by jcros            ###   ########.fr       */
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

static void	ft_free(t_philo *philos, pthread_mutex_t *forks);

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
		return (ft_err(EUNKN), 1);
	philos = malloc(sizeof(t_philo) * data.philo_count);
	if (!philos)
		return (ft_free(NULL, forks), ft_err(EUNKN));
	ft_init_philos(philos, &data, forks);
	if (!ft_spawn_threads(&data, philos))
		return (ft_free(philos, forks), ft_err(ETHRD));
	free(forks);
	free(philos);
	return (0);
}

static void	ft_free(t_philo *philos, pthread_mutex_t *forks)
{
	if (forks)
		free(forks);
	if (philos)
		free(philos);
}
