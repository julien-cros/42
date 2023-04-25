/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:27:59 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 10:38:48 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "struct.h"
#include "utils.h"
#include "strs.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && nmemb > SIZE_MAX / size)
		return (0);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	return ((void)ft_memset(s, 0, n));
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*buffer;

	i = 0;
	buffer = s;
	while (i < n)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (s);
}


t_pipex	*ft_init()
{
	t_pipex *pipex;
	
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (NULL);
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->valid_file = 0;
	pipex->here_doc = false;
	pipex->cmds = NULL;
	pipex->cmds_count = 0;
	pipex->cmds_path = NULL;
	pipex->out_name = NULL;
	return (pipex);
}