/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 18:30:50 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "parsing.h"


int main(int argc, char **argv)
{
	
	t_pipex *pipex;
	pipex = malloc(sizeof(t_pipex));
	pipex->here_doc = false;
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	return (ft_valid_args(argc, argv, pipex), 1);
		
}
