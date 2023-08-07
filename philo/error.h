/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 13:41:36 by juliencros        #+#    #+#             */
/*   Updated: 2023/07/29 11:58:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define EARGS "error: invalid arguments,\n-1 = number of philosophers,\n-2 = time to die,\n-3 = time to eat,\n-4 = time to sleep,\n-5 = number of time each philosopher must eat (optional)"
# define EUNKN "error: unknown error"
# define ETHRD "error: thread error"

int ft_error(char *error);

#endif