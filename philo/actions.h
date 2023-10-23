/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:07:19 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/23 13:40:26 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# include "structs.h"

void	*ft_single_philo(void *arg);
void	*ft_multiple_philos(void *arg);
void	ft_eat(t_philo *philo);
void	ft_sleep_and_think(t_philo *philo);

#endif