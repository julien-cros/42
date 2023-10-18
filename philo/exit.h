/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 09:36:31 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 14:29:43 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "structs.h"
# include "stdbool.h"

void	ft_wait_for_exit(t_data *data, t_philo *philos);
t_bool	ft_did_die(t_data *data, t_philo *philo);

#endif