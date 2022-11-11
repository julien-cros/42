/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:14:17 by jcros             #+#    #+#             */
/*   Updated: 2022/11/11 15:32:29 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalnum (int i)
{
    if ((i >= 65 && i <= 90)
     || (i >= 97 && i <= 122) 
     || (i >= '0' && i <= '9'))
        return (1);
    else
        return (0);
}