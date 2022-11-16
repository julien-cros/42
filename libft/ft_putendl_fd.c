/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:06:00 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/16 19:25:35 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    if(!s || !fd)
        return ;
       while (*s)
       {
        ft_putchar_fd(*s, fd);
        s++;
       }
    ft_putchar_fd('\n', fd);
}