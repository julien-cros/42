/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:42:13 by jcros             #+#    #+#             */
/*   Updated: 2023/12/08 10:02:23 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>

int				ft_printf(const char *format, ...);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
int				ft_putnbr_fd(int n, int fd);
unsigned int	ft_putunnbr_fd(unsigned int nb, int fd);
int				ft_putptr_fd(void *ptr, int fd);
int				ft_putnbr_base_fd(unsigned long n, char *base, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putchar_fd(char c, int fd);
char			*ft_strchr(const char *s, int c);

#endif