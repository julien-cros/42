/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:54:40 by juliencros        #+#    #+#             */
/*   Updated: 2023/05/01 13:38:13 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HERE_DOC_H
# define HERE_DOC_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "display.h"
# include "struct.h"
# include "strs.h"
# include "free.h"
# include "utils.h"

int	ft_here_doc(char **argv, t_pipex *pipex);
char	*ft_get_line(char *line, char limitter, int fd);
// int	ft_check_heredoc(char **argv, t_pipex *pipex);

#endif