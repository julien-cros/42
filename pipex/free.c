/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:47:10 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 19:16:59 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void ft_free_pipex(t_pipex *pipex)
{
	if (pipex->in_fd)
		close (pipex->in_fd);
	if (pipex->out_fd)
		close(pipex->out_fd);
	free(pipex);
}