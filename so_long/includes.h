/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:05:00 by codespace         #+#    #+#             */
/*   Updated: 2023/05/16 10:41:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include "struct.h"
#include "mlx/mlx.h"

//------------------    display.c   ------------------//

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

//------------------    errors.c    ------------------//

void	ft_no_map();
void	error_lenght_line();
void	error_wrong_character(char c);
void	error_square();
void	error_wall();
void	ft_error_finding_exit();
void	ft_error_collectible();
void	ft_invalid_map();

//------------------   find_valid.c ------------------//

int	ft_find_if_possible(t_map *map);
int	ft_change_position(t_map *map, char c, int way);
int ft_go_back(t_map *map);
int ft_find_character(t_map *map, char c);
char **ft_create_2d(t_map *map);

//------------------      free.c    ------------------//

void	ft_clean(t_map *map);
void	ft_free_with_i(char **strs, int i);
int		ft_close_mlx(t_data *data);

//------------------      mem.c     ------------------//

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

//------------------     utils.c    ------------------//

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
int ft_find_p(char **strs, t_map *map);

//------------------   valid_map.c  ------------------//

int ft_valid_map(t_map *map, int fd);


//------------------   create_window.c  ------------------//
void ft_init_window(t_map *map);
int ft_on_render(t_data *data);

//------------------   hooks.c  ------------------//

int ft_move(int keysym, t_data *data);
int ft_check_move(int keysym, t_data *data);
void ft_check_reachable(t_data *data);
void ft_what_print(t_data *data);
//------------------   init.c  ------------------//
void ft_init_data(t_data *data, t_map *map);

//------------------   textures.c  ------------------//
void ft_init_texture(t_data *data);
void ft_init_map(t_data *data);

//------------------   itoa.c  ------------------//
char	*ft_itoa(int n);

#endif