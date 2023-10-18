/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:00:45 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/18 13:37:16 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

# include <stdbool.h>

int		ft_atoi(const char *ptr);
bool	ft_isdigit(char c);
bool	ft_isdigit_str(char *str);

#endif