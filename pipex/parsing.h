/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:08:56 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/13 19:01:58 by juliencros       ###   ########.fr       */
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
#include "split.h"
#include "error.h"

int ft_check_heredoc(char **argv, t_pipex *pipex);
int ft_parse_cmds(int argc, char **argv, t_pipex *pipex);
char *ft_path_cmds(char *cmd, char **envp);

#endif