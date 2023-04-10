/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:14:33 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/10 10:59:52 by juliencros       ###   ########.fr       */
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
	int in_fd; //le fd d'entree
	int out_fd; // le fd de sortie;
	// int valid_cmds; // 0pour les deux bonnes 1 pour la premiere et pas l'autre 2 pour la seconde mais pas l'autre 3 pour les deux mauvaises;
	int valid_file; //1 pour valide 0 pour pas valide;
	t_bool here_doc; // vrai si je fais un here_doc et faux si non;
	char **cmds;
	char *out_name;
	int cmds_count;
	char *file;
} t_pipex;

#endif