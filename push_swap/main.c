/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:35:23 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/15 13:49:00 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "display.h"
#include "strings.h"
#include "utils.h"
#include "parse.h"
#include "split.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	t_args *args;

	if (argc == 1)
		return (0);
	args = ft_parse_args(argc, argv);
	if (
		!args || ft_replace_args_by_indices(&(args->int_array), args->count) == -1)
		return (0);
	ft_sort_args(args->int_array, args->count);
	ft_free_args(args, true);
	return (0);
}
