/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:33 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/27 11:13:10 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pipex
{
	t_bool	here_doc;
	t_bool	invalid_in;
	int		in_fd;
	int		out_fd;
	int		valid_file;
	int		cmds_count;
	char	*out_name;
	char	*file;
	char	***cmds;
	char	**cmds_path;
}	t_pipex;

#endif