/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:33 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 17:01:57 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pipex
{
	int in_fd;
	int out_fd;
	t_bool here_doc;
} t_pipex;

#endif