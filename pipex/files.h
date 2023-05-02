/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:29:40 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/02 14:41:23 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <unistd.h>
# include <stdio.h>
# include "struct.h"
# include "strs.h"
# include "error.h"
# include "here_doc.h"
# include "ft_urandom.h"

int	ft_check_file(char **argv, t_pipex *pipex);
int	ft_init_out(int argc, char **argv, t_pipex *pipex);
int	ft_create_valid_in(char **argv, t_pipex *pipex);
int	ft_create_invalid_in(t_pipex *pipex);

#endif