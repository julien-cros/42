/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_urandom.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:59:09 by codespace         #+#    #+#             */
/*   Updated: 2023/05/02 14:46:32 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_URANDOM_H
# define FT_URANDOM_H

# include "struct.h"
# include <unistd.h>
# include <stdio.h>
# include "here_doc.h"
# include <fcntl.h>

int	ft_urandom(t_pipex *pipex);

#endif