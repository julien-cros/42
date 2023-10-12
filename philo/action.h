/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:07:19 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/12 14:47:27 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "structs.h"

void	*ft_single_philo(void *arg);
void	*ft_multiple_philos(void *arg);
void	ft_print(t_philo *philo, char *msg, int arg_ms);
void	ft_eat(t_philo *philo);
void	ft_sleep_and_think(t_philo *philo);

#endif