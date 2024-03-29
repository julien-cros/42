/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:41:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/10/12 14:58:23 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define EARGS "error: invalid arguments"
# define EUNKN "error: unknown error"
# define ETHRD "error: thread error"

int	ft_err(char *err);

#endif