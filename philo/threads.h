/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 22:59:46 by juliencros        #+#    #+#             */
/*   Updated: 2023/07/01 23:02:42 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

# include "structs.h"

int ft_create_threads(t_data *data, pthread_mutex_t *forks, t_philos *philos);

#endif