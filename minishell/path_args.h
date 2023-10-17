/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_args.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:28:21 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/15 11:24:45 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_ARGS_H
# define PATH_ARGS_H

# include "structs.h"

bool ft_get_path_and_args(t_data *data, t_token *token);
void	ft_exec_cmd(t_data *data, t_token *token);

#endif