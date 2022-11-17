/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcros <jcros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:58:58 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/17 10:25:46 by jcros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;

	if (nmemb * size < size)
		return (0);
	calloc = malloc(size * nmemb);
	if (!calloc)
		return (0);
	ft_bzero(calloc, nmemb * size);
	return (calloc);
}
