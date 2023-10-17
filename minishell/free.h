/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 13:56:20 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/14 19:03:18 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "structs.h"
#include <stdbool.h>
# include <stdlib.h>

// bool	ft_clear_tokens(t_token **tokens);
void	ft_free_env(t_env *env);
void	ft_free_tab(char **tab);
void	ft_free_array(char **array, int n);
#endif