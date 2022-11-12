/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 21:05:04 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/12 15:00:12 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t word_count(const char *str, char sep)
{
	size_t i;
	size_t count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == sep && str[i+1] != sep)
			count++;
		i++;
	}
	printf("\nwordcount:\n count: %zu\n\n\n", count);
	return (count);
}

char **fill_split(char **split, char const *str, char sep)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] != sep && str[i])
		{
			split[k][j] = str[i];
			j++;
			i++;
		}
		split[k][j] = '\0';
		printf("fill_split:\n split:%s\n\n\n", split[k]);
		if (str[i] == sep && str[i+1] != sep && str[i])
			k++;
		while (str[i] == sep)
			i++;
	}
	//printf("\n\n\n\nstr[1]:%s \nstr[2]:%s \nstr[3]:%s \nstr[4]\n\n\n\n", split[0], split[1], split[2], split[3]);
	return (split);
}

char **size_split(char **split, char const *str, char sep)
{
	size_t indexstr;
	size_t indsexsplit;
	size_t count;

	indexstr = 0;
	indsexsplit = 0;
	count = 0;
	while (str[indexstr])
	{
		if (str[indexstr] == sep && str[indexstr+1] != sep && str[indexstr+1]) //i = sep && i+1 != sep
		{
			indsexsplit++;
			indexstr++;
		}
		while (str[indexstr] == sep)  // i == sep
		{
			indexstr++;
		}
		count = 0;
		while (str[indexstr] != sep && str[indexstr]) // i != sep
		{
			indexstr++;
			count ++;
		}
		printf("size_split:\n count: %zu\n indexstr: %zu\n indexsplit: %zu\n\n\n", count, indexstr, indsexsplit);
		split[indsexsplit] = (char *)malloc(sizeof(char) * count + 1);
		if (!split)
			return NULL;
	}
	return (split);
}

char **ft_split(char const *str, char sep)
{
	size_t count;
	char **split;

	if (!str)
		return (0);
	while (*str == sep)
			str++;
	printf("str:\n %s\n\n\n", str);
	count = word_count(str, sep);
	split = (char **)malloc(sizeof(char) * (count + 1));
	//split[count +1] = '\0';
	printf("MOK\n\n\n");
	split = size_split(split, str, sep);
	if (!split)
		return NULL;
	printf("MOK2\n\n\n");
	fill_split(split, str, sep);
	return (split);
}

// int main()
// {

// 	char *str = "julien cros est beau";
// 	char sep = ' ';
// 	char **split;
// 	split = ft_split(str, sep);
// 	int i = 0;
// 	int j = 0;
// 	int count = 0;
// 	while (split[j])
// 	{
// 		i = 0;
// 		printf("split[%d]: ", count);
// 		while (split[j][i])
// 		{
// 			printf("%c", split[j][i]);
// 			i++;
// 		}
// 		printf("\n");
// 		count ++;
// 		j++;
// 	}
// 	return (0);
// }








// size_t indexstr;
	// size_t i;
	// size_t j;

	// indexstr = 0;
	// i = 0;
	// j = 0;
	// while (str[indexstr])
	// {
	// 	if (str[indexstr] == sep && str[indexstr+1] != sep && str[indexstr+1])
	// 	{
	// 		i++;
	// 		indexstr++;
	// 	}
	// 	while (str[indexstr] == sep)
	// 	{
	// 		indexstr++;
	// 	}
	// 	j = 0;
	// 	while (str[indexstr] != sep && str[indexstr])
	// 	{
	// 		indexstr++;
	// 		split[i][j] = str[indexstr];
	// 	}
	// 	printf("fill_split:\n split:%s\n\n\n", split[i]);
	// }
	// return (split);