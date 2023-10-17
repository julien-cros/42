/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:20:26 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/14 19:00:33 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "structs.h"
# include "int.h"
# include "str.h"

size_t			ft_env_len(t_env *lst);
char			*ft_env_to_str(t_env *lst);
int				ft_init_env(t_data *data, char **envp_array);
int				ft_init_secret_env(t_data *data, char **env_array);
char			*ft_get_env_value(char *name, t_env *env);  //TODO max function per file
char			*ft_get_env_name(char *env_name, char *env);
char			**ft_get_paths(t_env *envp);

#endif