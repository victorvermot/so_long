/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:51:49 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/13 15:30:52 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	*ft_memcpy(void *dst, const void *src, int n)
{
	unsigned char		*dest;
	const unsigned char	*source;
	int					i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	dest = dst;
	source = src;
	while (n > 0)
	{
		dest[i] = source[i];
		i++;
		n--;
	}
	return (dst);
}
