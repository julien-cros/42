/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:35:23 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/03 12:42:47 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "display.h"
#include "strings.h"
#include "utils.h"
#include "parse.h"
#include "split.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_args *args;

	if (argc == 1)
		return (0);
	args = ft_parse_args(argc, argv);
	// printf("aft parse\n");
	if (!args || ft_replace_by_indices(&(args->int_array), args->count) == -1)
		return (0);
	// printf("aft replace indices\n");
	ft_sort_args(args->int_array, args->count);
	// printf("aft sort\n");
	free(args->int_array);
	if (args->is_malloced)
		ft_free(args->str_array, args->count);
	free(args);
	return (0);
}