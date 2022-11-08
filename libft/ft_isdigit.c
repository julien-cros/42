/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:09:03 by jcros             #+#    #+#             */
/*   Updated: 2022/11/07 14:38:43 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit (int i)
{
 if (i >= '0' && i <= '9')
    return (1);
else
    return (0);
}