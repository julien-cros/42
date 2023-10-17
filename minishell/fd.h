/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:23:11 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/14 15:27:13 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_H
# define FD_H

# include "structs.h"

void	ft_close(int fd);
void	ft_close_fds(t_data *data);
void	ft_reset_fds(t_data *data);
void	ft_reset_std(t_data *data);

#endif