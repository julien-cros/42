/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_func.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:58:17 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/16 16:39:03 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_FUNC_H
# define BUILTINS_FUNC_H

# include "structs.h"

int		ft_env(t_data *data);
// int		ft_unset(t_data *data);
int		ft_pwd(t_data *data);
int		ft_cd(t_data *data);
int		ft_exit(t_data *data);
#endif