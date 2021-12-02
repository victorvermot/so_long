/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                           :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:34:34 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/14 17:00:18 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_lennbr(int n)
{
	int	len;

	if (n < 0 || n == 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_swap(char *s, int isMax, int size)
{
	int		i;
	char	temp;

	i = 0;
	if (isMax)
		s[0] = '8';
	while (i < size - 1)
	{
		temp = s[i];
		s[i] = s[size - 1];
		s[size - 1] = temp;
		i++;
		size--;
	}
	return (s);
}

static char	*ft_malloc(int n, int len, char *ret)
{
	if (n == 0)
	{
		ret = (char *)malloc(sizeof(char) * 2);
		ret[0] = '0';
	}
	else
		ret = (char *)malloc(len + 1);
	return (ret);
}

static char	*ft_check_number(int *n, int *isMax, int *isNegative, char *ret)
{
	int	i;

	i = 0;
	if (*n == -2147483648)
	{
		*isMax = 1;
		*n = *n + 1;
	}
	if (*n < 0)
	{
		*n *= -1;
		*isNegative = 1;
	}
	if (*n == 0)
		return (ret);
	while (*n != 0)
	{
		ret[i++] = (*n % 10) + '0';
		*n /= 10;
	}
	if (isNegative)
		ret[i++] = '-';
	return (ret);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ret;
	int		i;
	int		is_max;
	int		is_negative;

	is_negative = 0;
	is_max = 0;
	i = 0;
	len = ft_get_lennbr(n);
	ret = NULL;
	ret = ft_malloc(n, len, ret);
	if (!ret)
		return (NULL);
	ret = ft_check_number(&n, &is_max, &is_negative, ret);
	ft_swap(ret, is_max, len);
	ret[len] = '\0';
	return (ret);
}
