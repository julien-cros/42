/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:57:23 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/04 21:43:22 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
#define ERRORS_H

#include "display.h"

void	ft_no_map();
void	error_lenght_line();
void	error_wrong_character(char c);
void	error_square();
void	error_wall();
void	ft_error_finding_exit();
#endif