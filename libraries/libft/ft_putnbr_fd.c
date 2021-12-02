/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:34:34 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/14 16:59:13 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_putnbr_recu(int n, int fd)
{
	int		i;
	char	temp;

	i = -1;
	if (n == -2147483648)
	{
		n *= -1;
		ft_putnbr_recu(n / 10, fd);
		temp = '8';
		write(fd, &temp, sizeof(temp));
	}
	else if (n < 0)
	{
		n *= -1;
		temp = '-';
		write(fd, &temp, sizeof(temp));
	}
	if (n > 0)
	{
		ft_putnbr_recu(n / 10, fd);
		temp = (n % 10) + 48;
		write(fd, &temp, sizeof(temp));
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	temp;

	temp = '0';
	if (n == 0)
		write(fd, &temp, sizeof(temp));
	else
		ft_putnbr_recu(n, fd);
}
