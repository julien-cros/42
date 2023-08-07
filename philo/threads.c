/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 23:03:20 by juliencros        #+#    #+#             */
/*   Updated: 2023/08/04 19:02:04 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"
#include <stdio.h>
#include <pthread.h>
#include "error.h"
#include "init.h"
#include "free.h"
#include "state.h"
#include "time.h"
#include "eat.h"
#include "sleep.h"
#include <sys/time.h>
#include <unistd.h>
#include "ft_print.h"

t_bool	ft_create_philos(t_data *data, t_philos *philos);
void	*ft_philo(void *arg);
void	ft_close_threads(t_data *data, t_philos *philos);
t_bool	ft_unlock_all_forks(t_philos *philos);
// void	ft_check_ready(t_philos *philos);
// void	ft_wait_for_all_philos(t_philos *philos);

t_bool	ft_create_threads(t_data *data, t_philos *philos)
{
	if (ft_init_mutex(data, philos) == false)
		return (false);
	// if (ft_unlock_all_forks(philos) == false)
		// return (ft_close_threads(data, philos), false);
	if (ft_create_philos(data, philos) == false)
		return (ft_close_threads(data, philos), false);
	return (ft_close_threads(data, philos), true);
}

t_bool	ft_create_philos(t_data *data, t_philos *philos)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&philos[i].thread, NULL, &ft_philo, &philos[i]) != 0)
			return (false);
		i++;
	}
	pthread_mutex_lock(&data->data_mutex);
	data->start_time = ft_get_time();
	data->is_ready = true;
	pthread_mutex_unlock(&data->data_mutex);
	return (true);

}

void	*ft_philo(void *arg)
{
	t_philos	*philos;
	philos = (t_philos *)arg;
	while (pthread_mutex_lock(&philos->data->data_mutex) == 0
		&& !philos->data->is_ready)
		{
			pthread_mutex_unlock(&philos->data->data_mutex);
		}
	pthread_mutex_unlock(&philos->data->data_mutex);
	ft_print(philos, "has been created", 0);
	if (philos->id != 1)
	{
		pthread_mutex_lock(&philos->data->data_mutex);
		usleep(philos->data->time_to_eat * 0.9 + 1);
		pthread_mutex_unlock(&philos->data->data_mutex);
	}
	while (pthread_mutex_lock(&philos->data->data_can_eat_mutex) == 0
		&& !philos->data->is_game_over)
	{
		pthread_mutex_unlock(&philos->data->data_can_eat_mutex);
		ft_is_eating(philos);
		ft_is_sleeping(philos);
		if (ft_check_state(philos) == false)
			break ;
	}
	return (NULL);
}

t_bool ft_unlock_all_forks(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->data->num_philo)
	{
		if (pthread_mutex_init(philos[i].left_fork, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

// void		ft_check_ready(t_philos *philos)
// {
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philos->data->data_mutex);
// 		if (philos->data->is_ready == true)
// 		{
// 			pthread_mutex_unlock(&philos->data->data_mutex);
// 			usleep(100);
// 		}
// 		pthread_mutex_unlock(&philos->data->data_mutex);
// 		pthread_mutex_lock(&philos->data->data_mutex);
// 		if (philos->data->is_ready == true)
// 		{
// 			pthread_mutex_unlock(&philos->data->data_mutex);
// 			return ;
// 		}
// 		pthread_mutex_unlock(&philos->data->data_mutex);
// 	}
	
// }


//  void	ft_wait_for_all_philos(t_philos *philos)
//  {
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philos->data->data_mutex);
// 		if (philos->data->is_ready == true)
// 			usleep(1);
// 		if (philos->data->is_ready == true)
// 			break ;
// 		pthread_mutex_unlock(&philos->data->data_mutex);
// 	}
//  }


	// ft_create_threads(data, forks, philos);
	// ft_unlock_forks(forks, philos);
	// ft_check_state(philos, data);
	// \_> change status() if something changed in the status
	// recursif jusqu'a ce que is_game_over == 1 ou max_eat == number_of_eat