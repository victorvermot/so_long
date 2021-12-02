/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:11:09 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/13 17:32:41 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = -1;
	i = -1;
	while (dst[++i])
		;
	if (dstsize == 0)
	{
		while (src[++j])
			;
		return (j);
	}
	if (dstsize <= i)
		i = dstsize;
	while (src[++j])
	{
		if (i < dstsize - 1)
			dst[i] = src[j];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
