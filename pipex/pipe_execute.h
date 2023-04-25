/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_execute.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:12:42 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:27:54 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_EXECUTE_H
# define PIPE_EXECUTE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include "struct.h"

int	ft_pipex(t_pipex *pipex, char **envp, int i);

#endif