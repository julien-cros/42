/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:40:38 by juliencros        #+#    #+#             */
/*   Updated: 2023/09/25 11:06:40 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "structs.h"

// void	ft_free_data(t_data *data);
// void	ft_free_data_mutex(t_data *data, pthread_mutex_t *mutex);
// // void	ft_free(t_data *data, pthread_mutex_t *mutex, t_philos **philos);
// void	ft_free(t_philos *philos, pthread_mutex_t *mutex);
// void	ft_close_threads(t_data *data, t_philos *philos);
// void	ft_free_mutex(t_data *data);
void	ft_destroy_threads(t_data *data, t_philos *philos);

#endif