/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:11:37 by codespace         #+#    #+#             */
/*   Updated: 2023/05/11 22:03:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void ft_clean(t_map *map)
{
	if (map->plan)
		free(map->plan);
	if (map->strs)
		ft_free_with_i(map->strs);
	free(map);
}

void	ft_free_with_i(char **strs)
{
	int	j;

	j = 0;
	{
		while (strs[j])
		{
			free(strs[j]);
			j++;
		}
	}
	free(strs);
}