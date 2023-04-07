/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:08:56 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/07 18:56:02 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "utils.h"
#include "strs.h"
#include "display.h"
#include "struct.h"
#include "here_doc.h"
#include "free.h"

int ft_valid_args(int argc, char **argv, t_pipex *pipex);

#endif