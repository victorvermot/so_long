/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd                                        :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:34:34 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/14 17:01:28 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int		i;
	char	bs;

	bs = '\n';
	i = -1;
	if (s)
	{
		while (s[++i])
			write(fd, &s[i], sizeof(s[i]));
		write(fd, &bs, sizeof(s[i]));
	}
}
