/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:43:35 by juliencros        #+#    #+#             */
/*   Updated: 2023/09/26 14:28:52 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "stdlib.h"
#include "stdio.h"

int	ft_error(char *err)
{
	printf("philo: %s\n", err);
	exit(1);
	return (1);
}
