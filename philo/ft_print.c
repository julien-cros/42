/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 17:47:24 by codespace         #+#    #+#             */
/*   Updated: 2023/08/04 17:53:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
#include <stdio.h>

void	ft_print(t_philos *philos, char *str, long int time)
{
	pthread_mutex_lock(&philos->data->print_mutex);
	printf("[%ldms] %d %s\n", time, philos->id, str);
	pthread_mutex_unlock(&philos->data->print_mutex);
}