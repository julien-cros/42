/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:46:59 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/12 11:03:05 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "structs.h"

t_args	*ft_parse_args(int argc, char **argv);
t_args	*ft_get_args_from_argv(int argc, char **argv);
t_args	*ft_get_args_from_str(char *str);
void	ft_check_if_args_are_numbers(t_args *arg, int count);
void	ft_check_duplicates(t_args *arg);

#endif