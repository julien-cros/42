/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:33 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/19 21:16:10 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pipex
{
	t_bool here_doc; // vrai si je fais un here_doc et faux si non;
	int in_fd; //le fd d'entree
	int out_fd; // le fd de sortie;
	int valid_file; //1 pour valide 0 pour pas valide;
	int cmds_count;
	char *out_name;
	char *file;
	char ***cmds;
	char **cmds_path;
} t_pipex;

#endif