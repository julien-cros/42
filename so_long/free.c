/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:11:37 by codespace         #+#    #+#             */
/*   Updated: 2023/05/11 13:25:18 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void ft_clean(t_map *map)
{
	int i;

	i = 0;
	if (map->plan)
		free(map->plan);
	if (map->strs[i])
		ft_free_with_i(map->strs);
	free(map);
}

void	ft_free_with_i(char **strs)
{
	int	j;

	j = 0;
	{
		printf("strs[%d] = %s\n", j, strs[j]);
		while (strs[j])
		{
			free(strs[j]);
			j++;
		}
	}
	free(strs);
}