/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:34:34 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/14 16:55:23 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_get_beginning(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	begin;

	j = -1;
	i = -1;
	begin = ft_strlen(s1);
	while (s1[++i])
	{
		while (set[++j])
		{
			if (s1[i] == set[j])
			{
				i++;
				j = -1;
			}
		}
		begin = i;
		break ;
	}
	return (begin);
}

static int	ft_get_ending(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	end;

	j = -1;
	end = ft_strlen(s1);
	i = ft_strlen(s1);
	while (--i)
	{
		while (set[++j])
		{
			if (s1[i] == set[j])
			{
				i--;
				j = -1;
			}
		}
		end = i;
		break ;
	}
	if (end < 0)
		return (ft_strlen(s1));
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	char	*ret;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	begin = ft_get_beginning(s1, set);
	end = ft_get_ending(s1, set);
	i = 0;
	ret = malloc(sizeof(char) * ((end - begin) + 2));
	if (!ret)
		return (NULL);
	while (begin <= end)
		ret[i++] = s1[begin++];
	ret[i] = '\0';
	return (ret);
}
