/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:42:13 by jcros             #+#    #+#             */
/*   Updated: 2022/11/09 12:58:51 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void *ft_memset (void *b, int c, size_t n);
int ft_isalnum (int i);
void ft_bzero (void *str, size_t n);
int ft_isalpha (int i);
int ft_isascii(int i);
int ft_isdigit (int i);
int ft_isprint (int i);
char *ft_memcpy (void *dest, const void *src, size_t n);
size_t ft_strlen (char *str);
void *ft_memmove (void *dest, const void *src, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t size);
size_t ft_strlcat(char *dst, const char *src, size_t size);
int ft_toupper(int c);
int ft_tolower(int c);
char *ft_strchr(const char *s, int c);
void *ft_memchr(const void *s, int c, size_t n);
char *ft_strrchr(const char *s, int c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
char *ft_strnstr(const char *big, const char *little, size_t len);
int ft_atoi(const char *nptr);
char *ft_strdup(const char *s);