/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_urandom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:00:42 by codespace         #+#    #+#             */
/*   Updated: 2023/05/02 13:41:45 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_urandom.h"

int ft_urandom(t_pipex *pipex)
{
    char *line;
    int fd;
    int urandom_fd;
    
    line = malloc(10000 * sizeof(char));
    if (!line)
        return (-1);
    fd = open(".urandom_fd", O_RDWR | O_CREAT | O_TRUNC , 0644);
    urandom_fd = open("/dev/urandom", O_RDONLY);
    if (ft_get_line(line, '\0', urandom_fd))
    {
        if (!line)
            return (-1);
        ft_putstr_fd(line, fd);
        free(line);
        close(urandom_fd);
        close(fd);
        pipex->in_fd = open(".urandom_fd", O_RDONLY);
        pipex->urandom = true;
        return (0);
    }
    return (-1);
}