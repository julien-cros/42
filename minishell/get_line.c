/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:39:30 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/14 15:21:09 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

char	*ft_get_line(char *line, char limiter, int fd)
{
	int		i;
	char	buffer;

	i = 0;
	if (!line)
		return (NULL);
	while (read(fd, &buffer, 1) > 0 && buffer != limiter)
	{
		line[i] = buffer;
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}
