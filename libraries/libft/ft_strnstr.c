/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 12:22:39 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/13 15:24:39 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	char		*ptr;

	j = 0;
	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] && len > i)
	{
		if (haystack[i] == needle[j])
		{
			ptr = (char *)&haystack[i];
			while (haystack[i + j] == needle[j] && len > i + j && needle[j])
			{
				j++;
				if (!needle[j])
					return (ptr);
			}
		}
		i++;
		j = 0;
	}
	return (0);
}
