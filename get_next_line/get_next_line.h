/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:18:57 by juliencros        #+#    #+#             */
/*   Updated: 2022/12/04 14:23:53 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEX_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

char	*get_next_line(int fd);

#endif