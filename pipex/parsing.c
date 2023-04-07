/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:12:44 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 18:19:04 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int ft_valid_args(int argc, char **argv, t_pipex *pipex)
{
	if (argc <= 5)
		return (ft_putstr_fd("to few arguments", 1), -1);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
	{
		pipex->here_doc = true;
		if (ft_here_doc(argv, pipex) < 1)
			return (-1);
	}
	else 
		printf("it's not ok\n%s\n", argv[1]);
	return (0);
}
