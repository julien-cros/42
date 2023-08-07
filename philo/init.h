/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:06:52 by juliencros        #+#    #+#             */
/*   Updated: 2023/08/04 17:16:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

#include "structs.h"
#include "pthread.h"

int		ft_init_parse(int argc, char **argv, t_data *data);
void	ft_init_philos(t_philos *philos, t_data *data, pthread_mutex_t *forks);
t_bool	ft_init_mutex(t_data *data, t_philos *philos);

#endif
