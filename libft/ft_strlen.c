/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:45:19 by jcros             #+#    #+#             */
/*   Updated: 2022/11/07 11:46:15 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen (char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return(i);
}