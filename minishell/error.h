/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:38:36 by herbie            #+#    #+#             */
/*   Updated: 2023/10/14 13:19:31 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define M "minishell: "
# define ER_ECMD "invalid command"
# define ER_EMALLOC "malloc error"
# define ER_EUKN "unknown error"
# define ER_ENOENT "no such file or directory"
# define ER_ESYN "syntax error near unexpected token"

# include "structs.h"

// @deprecated
void	old_ft_error(char *msg);
void	ft_invalid_token(t_lexer lexer, t_token token);

#endif /* ERROR_H */
