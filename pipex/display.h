/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:11:57 by juliencros        #+#    #+#             */
/*   Updated: 2023/04/25 13:36:32 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include <unistd.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_puchar_fd(char c, int fd);

#endif