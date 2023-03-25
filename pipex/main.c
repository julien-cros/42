/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/24 18:38:41 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char **argv, char **env)
{
	int fd[2];
	if (pipe(fd) == -1)
	{
		return 1;
	}
	// int text = open("test", O_CREAT | O_RDWR);

	int pid1 = fork();
	if (pid1 < 0)
	{
		return 2;
	}
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("cat", "cat", "Makefile", NULL);
	}

	int pid2 = fork();
	if (pid2 < 0)
	{
		return 3;
	}

	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("wc", "wc", "-l", NULL);
	}

	close(fd[0]);
	close(fd[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

// par exemple lire un ficher , pipe donc ce que veux dire faire une autre commande et ecrire
// le resultat dans un nouveau fd
// <makefile cat | wc -l > out

// je cat dans un fd le makefile puis apres j'ecris dans un nouveau fd le resultat de la commande wc -l
// donc en gros j'ecris dans un nouveau fd ce que la commande retourne et j'ecris dans un nouveau fd ce que me retourne l'autre commande
// du fd de la premiere commande.

// ce que je doit ecrire:
// ./pipex makefile cat "wc -l" "out"