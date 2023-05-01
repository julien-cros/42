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

void	ft_cmds_error(char *cmd, int fd)
{
	write(fd, "bash: ", 6);
	ft_putstr_fd(cmd, fd);
	write(fd, ": command not found\n", 20);
}

void	ft_file_error(char *file, int fd)
{
	write(fd, "bash: ", 6);
	ft_putstr_fd(file, fd);
	write (fd, ": No such file or directory\n", 28);
}
