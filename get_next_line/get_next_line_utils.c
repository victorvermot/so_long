/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:08:15 by vvermot-          #+#    #+#             */
/*   Updated: 2021/10/28 14:02:39 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	ft_strlen(const char *s)
{
	unsigned long int	i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ret;

	i = -1;
	while (s1[++i])
		;
	ret = (char *)malloc(i * sizeof(const char) + 1);
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}

// Copie un string d'une longueur maximale de len commencant a l'index start
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*ret;

	i = 0;
	if (!s)
		return (NULL);
	if (start + len > ft_strlen(s))
		ret = malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		ret = (char *)malloc(len * sizeof(char) + 1);
	if (!ret)
		return (NULL);
	while (s[start] && start < len && start < ft_strlen(s))
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	j = -1;
	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(len * sizeof(char) + 1);
	if (!ret)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	while (s2[++j])
		ret[i++] = s2[j];
	ret[i] = '\0';
	free(s1);
	return (ret);
}
