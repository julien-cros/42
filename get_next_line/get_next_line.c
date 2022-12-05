/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:49 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/05 12:17:52 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *str;
	static int line;
	int i;

	line = 0;
	i = 0;
	if (!fd)
		return (0);
	str = malloc(sizeof(char) * BUFFER_SIZE);
	while (read(fd, str, BUFFER_SIZE) != '\n'
		|| read(fd, str, BUFFER_SIZE) !=0)
	{
		
	}
	if (read(fd, str, BUFFER_SIZE) == '\n'
		|| read(fd, str, BUFFER_SIZE) ==0)
		line++;
	
}


// int main()
// {
// 	char *str = "salut\n je suis moi et toi tu /n n'est pas moi";
// 	return (0);
// }


