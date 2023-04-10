/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:31:13 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/10 11:14:16 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_file.h" 

int ft_check_file(char **argv, t_pipex *pipex)
{
	if (pipex->here_doc == true)
		return (0);
	else if (access(argv[1], F_OK|R_OK) == 0)
	{
		pipex->file = (char *)malloc(ft_strlen(argv[1]) * sizeof(char) + 1);
		if (!pipex->file)
			return (1);
		pipex->file = ft_strdup(argv[1]);
		if (!pipex->file)
			return (1);
	}
	return (0);
}
