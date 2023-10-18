/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:13:04 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 13:41:01 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "int.h"

/** @brief The ft_parse_args function parses the arguments 
 * 	to fill the data.
 *
 * @param argc
 * @param argv
 * @param data
 * @return true
 * @return false
 */
t_bool	ft_parse_args(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (false);
	i = 0;
	while (++i < argc)
		if (!ft_isdigit_str(argv[i]))
			return (false);
	data->philo_count = ft_atoi(argv[1]);
	data->time_die_in_ms = ft_atoi(argv[2]);
	data->time_eat_in_ms = ft_atoi(argv[3]);
	data->time_sleep_in_ms = ft_atoi(argv[4]);
	if (argc == 6)
		data->max_eat = ft_atoi(argv[5]);
	if (data->philo_count < 1 || data->time_die_in_ms < 1
		|| data->time_eat_in_ms < 1 || data->time_sleep_in_ms < 1
		|| (argc == 6 && data->max_eat < 1))
		return (false);
	return (true);
}
