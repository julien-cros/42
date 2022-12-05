/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:49 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/04 19:58:34 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *str;
	
	if (!fd)
		return (0);
	str = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, str, BUFFER_SIZE) != '\n'
		|| read(fd, str, BUFFER_SIZE) !=0)
	{
		
	}
	
}


// int main()
// {
// 	char *str = "salut\n je suis moi et toi tu /n n'est pas moi";
// 	return (0);
// }


