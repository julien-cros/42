/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliencros <juliencros@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:58:58 by juliencros        #+#    #+#             */
/*   Updated: 2022/11/10 11:44:38 by juliencros       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    void *size_calloc;
    
    if (nmemb * size < size)
        return (0);
    size_calloc = malloc(sizeof(size) * nmemb);
    if(!size_calloc)
        return (0);
    ft_bzero(size_calloc, nmemb);
}