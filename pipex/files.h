/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 10:29:40 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:30:39 by jcros            ###   ########.fr       */
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

#endif