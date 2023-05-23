/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:05:00 by codespace         #+#    #+#             */
/*   Updated: 2023/05/23 22:43:58 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "struct.h"
# include "mlx/mlx.h"

//------------------    main.c      ------------------//

void	ft_init(t_map *map);

//------------------    display.c   ------------------//

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

//------------------    errors.c    ------------------//

void	ft_invalid_map(void);
void	ft_error(void);
void	ft_error_X11(void);
int		just_mlx(t_data *data);	
//------------------   find_valid.c ------------------//

int		ft_find_if_possible(t_map *map);
int		ft_change_position(t_map *map, char c, int way);
int		ft_go_back(t_map *map);
int		ft_find_character(t_map *map, char c);

//------------------   fill_map.c   ------------------//

char	*ft_fill_map(int fd);
char	**ft_create_2d(t_map *map);

//------------------      free.c    ------------------//

void	ft_clean(t_map *map);
void	ft_free_with_i(char **strs, int i);
int		ft_close_mlx(t_data *data);
void	ft_free_img(t_data *data);
void	ft_free_mlx(t_data *data);


//------------------      mem.c     ------------------//

void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);

//------------------     utils.c    ------------------//

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

//------------------   valid_map.c  ------------------//

int		ft_valid_map(t_map *map);
char	*ft_strjoinne(char *str, char c);
int		ft_check_chars(t_map *map);
int		ft_check_walls(t_map *map);
int		ft_check_length(t_map *map);

//------------------   create_window.c  ------------------//

void	ft_init_window(t_map *map);
int		ft_on_render(t_data *data);
int		ft_print_steps(t_data *data);

//------------------   hooks.c  ------------------//

int		ft_move(int keysym, t_data *data);
int		ft_check_move(int keysym, t_data *data);
void	ft_check_reachable(t_data *data);
void	ft_what_print(t_data *data, char c, int way);
int		ft_print_term(t_data *data);

//------------------   init.c  ------------------//

int		ft_init_data(t_data *data, t_map *map);
int		ft_init_img_path(t_data *data);
int		ft_find_p(char **strs, t_map *map);
//------------------   textures.c  ------------------//
int		ft_init_texture(t_data *data);
void	ft_init_map(t_data *data);
void	ft_what_image(t_data *data);

//------------------   itoa.c  ------------------//

char	*ft_itoa(int n);

#endif