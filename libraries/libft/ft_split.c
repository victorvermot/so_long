/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:34:34 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/13 19:09:31 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*ft_copy_words(char *buffer, char *ret, int *j, int *c)
{
	int	i;

	i = -1;
	buffer[*j] = '\0';
	ret = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	while (buffer[++i])
		ret[i] = buffer[i];
	ret[i] = '\0';
	i = -1;
	while (buffer[++i])
		buffer[i] = '\0';
	*j = 0;
	*c = *c - 1;
	return (ret);
}

static char	**ft_get_words_content(char const *s, char c, char **ret, int index)
{
	int		i;
	int		within;
	char	buffer[5000];
	int		j;

	j = 0;
	within = 1;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			within = 1;
		while (s[i] == c && s[i])
			i++;
		if (within && s[i] != c && s[i])
		{
			while (s[i] != c && s[i])
				buffer[j++] = s[i++];
			ret[index] = ft_copy_words(buffer, ret[index], &j, &i);
			index++;
		}
		within = 0;
	}
	return (ret);
}

static int	ft_get_words_numbers(char const *s, char c)
{
	int	i;
	int	within;
	int	count;

	count = 0;
	within = 1;
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
		{
			within = 1;
		}
		while (s[i] == c && s[i])
			i++;
		if (within && s[i] != c && s[i])
			count++;
		within = 0;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_get_words_numbers(s, c);
	ret = (char **)malloc(sizeof(char *) * count + 1);
	if (!ret)
		return (NULL);
	ret = ft_get_words_content(s, c, ret, 0);
	ret[count] = NULL;
	return (ret);
}
