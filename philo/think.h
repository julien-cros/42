/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:08:12 by codespace         #+#    #+#             */
/*   Updated: 2023/08/02 16:08:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THINK_H
# define THINK_H

# include "structs.h"

t_bool	ft_check_think(t_philos *philos, t_data *data);
void	ft_is_thinking(t_philos *philos, t_data *data);

#endif