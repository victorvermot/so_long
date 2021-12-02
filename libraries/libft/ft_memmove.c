/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 18:18:06 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/13 15:30:11 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;
	int					i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	dest = dst;
	source = src;
	if (dest < source)
	{
		while (len--)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (len--)
			dest[len] = source[len];
	}
	return (dst);
}
