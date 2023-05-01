/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:29:40 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 10:33:11 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILES_H
# define FILES_H

# include <unistd.h>
# include <stdio.h>
# include "struct.h"
# include "strs.h"
# include "error.h"

int		ft_check_file(int argc, char **argv, t_pipex *pipex);
void	ft_outfile(int argc, char **argv, t_pipex *pipex);
int     create_out_name(t_pipex *pipex, int argc, char **argv);
#endif