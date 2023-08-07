/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:43:35 by juliencros        #+#    #+#             */
/*   Updated: 2023/08/02 15:39:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "stdlib.h"
#include "stdio.h"

int ft_error(char *error)
{
	printf("philo: %s\n", error);
	exit(1);
}