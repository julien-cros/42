/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:15:06 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:16:59 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "struct.h"
# include "display.h"

void	ft_cmds_error(char *cmd, int fd);
void	ft_file_error(char *file, int fd);

#endif