/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:15:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:29:43 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_cmds_error(char *cmd)
{
	write(1, "bash: ", 6);
	ft_putstr_fd(cmd, 1);
	write(1, ": command not found\n", 20);
}

void	ft_file_error(char *file)
{
	write(1, "bash: ", 6);
	ft_putstr_fd(file, 1);
	write (1, ": No such file or directory\n", 28);
}
