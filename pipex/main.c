/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:01:02 by juliencros        #+#    #+#             */
/*   Updated: 2023/03/27 16:02:37 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n);

int main(int argc, char **argv, char **envp)
{

	char *const *args = {"/bin/wc", "hello world pd", NULL};
	// args = "/bin/sh";


	printf("%s", "HELLO");

	execve("/bin/wc", args, envp);
	
// 	int fd[2];
// 	if (pipe(fd) == -1)
// 	{
// 		return 1;
// 	}
// 	// int text = open("test", O_CREAT | O_RDWR);

// 	int pid1 = fork();
// 	if (pid1 < 0)
// 	{
// 		return 2;
// 	}
// 	if (pid1 == 0)
// 	{
// 		dup2(fd[1], STDOUT_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		if (ft_strncmp())
// 	}

// 	int pid2 = fork();
// 	if (pid2 < 0)
// 	{
// 		return 3;
// 	}

// 	if (pid2 == 0)
// 	{
// 		dup2(fd[0], STDIN_FILENO);
// 		close(fd[0]);
// 		close(fd[1]);
// 		execlp("wc", "wc", "-l", NULL);
// 	}

// 	close(fd[0]);
// 	close(fd[1]);

// 	waitpid(pid1, NULL, 0);
// 	waitpid(pid2, NULL, 0);
// 	return (0);
}


// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (n <= 0)
// 		return (0);
// 	while (s1[i] && s1[i] == s2[i] && i < n - 1)
// 		i++;
// 	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
// }

// char *args;
// args = "/bin/sh"
// par exemple lire un ficher , pipe donc ce que veux dire faire une autre commande et ecrire
// le resultat dans un nouveau fd
// <makefile cat | wc -l > out

// je cat dans un fd le makefile puis apres j'ecris dans un nouveau fd le resultat de la commande wc -l
// donc en gros j'ecris dans un nouveau fd ce que la commande retourne et j'ecris dans un nouveau fd ce que me retourne l'autre commande
// du fd de la premiere commande.

// ce que je doit ecrire:
// ./pipex makefile cat "wc -l" "out"