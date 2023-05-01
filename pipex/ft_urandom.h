/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_urandom.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:59:09 by codespace         #+#    #+#             */
/*   Updated: 2023/05/01 13:48:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_URANDOM_H
# define FT_URANDOM_H

#include "struct.h"
#include <unistd.h>
#include <stdio.h>
#include "here_doc.h"
#include <fcntl.h>

int ft_urandom(t_pipex *pipex);

#endif