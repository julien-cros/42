/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:29:40 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/01 12:36:16 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <unistd.h>
# include <stdio.h>
# include "struct.h"
# include "strs.h"
# include "error.h"
#include "here_doc.h"
#include "ft_urandom.h"

int		ft_check_file(char **argv, t_pipex *pipex);
// void	ft_outfile(int argc, char **argv, t_pipex *pipex);
// int     create_out_name(t_pipex *pipex, int argc, char **argv);
int ft_init_out(int argc, char **argv, t_pipex *pipex);
int ft_create_valid_in(char **argv, t_pipex *pipex);
int ft_create_invalid_in(t_pipex *pipex);

#endif