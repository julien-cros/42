/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:08:04 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/16 16:06:35 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    if (n == 2147483647)
    {
        ft_putstr_fd("2147483647", fd);
        return ;
    }   
    if (n == -2147483648)
    {
        ft_putstr_fd("-2147483648", fd);
        return ;
    }
    if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n *= -1;
    }
    if (n > 9)
        ft_putnbr_fd(n / 10, fd);
    ft_putchar_fd(n % 10 + 48, fd);
}

