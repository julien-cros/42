/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:43:35 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/12 14:56:43 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "stdlib.h"
#include "stdio.h"

int	ft_err(char *err)
{
	printf("philo: %s\n", err);
	exit(1);
	return (1);
}
