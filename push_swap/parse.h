/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:46:59 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/01 21:24:52 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
#define PARSE_H

#include <limits.h>

typedef enum e_bool
{
	false,
	true
} t_bool;

typedef struct args
{
	char **str_array;
	int *int_array;
	int count;
	t_bool is_malloced;
} t_args;

t_args *ft_parse_args(int argc, char **argv);
t_args *ft_split_args(char *str);
t_args *get_args(int argc, char **argv);
void ft_check_num(t_args *arg, int count);
void ft_check_duplicate(t_args *arg);

#endif