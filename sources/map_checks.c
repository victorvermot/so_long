/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:38:24 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/29 19:37:02 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*check_middle_line(char *l, t_board *board, int len, char *map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (l[k] && l[k] != '\n')
		k++;
	board->num_col = k;
	if (l[0] != '1' || l[k - 1] != '1' || len != k)
		return (NULL);
	while (l[++i])
	{
		if (l[i] == '1' || l[i] == '0' || l[i] == '\n' || l[i] == 'X')
			continue ;
		else if (l[i] == 'C')
			board->num_c += 1;
		else if (l[i] == 'P')
			board->num_s += 1;
		else if (l[i] == 'E')
			board->num_e += 1;
		else
			return (NULL);
	}
	map = ft_strdup(l);
	return (map);
}

static char	*check_first_last_line(char *line, char *map)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != '\n')
			return (NULL);
	}
	map = ft_strdup(line);
	return (map);
}

char	**get_num_lines(int fd, t_board *board)
{
	int		count;
	int		file;
	char	c[2561];
	int		i;

	i = 0;
	file = read(fd, c, 1);
	count = 0;
	if (file <= 0)
		kill_app(1, board->board, 0);
	while (file)
	{
		file = read(fd, c, 2560);
	}
	while (c[i])
	{
		if (c[i] == '\n' && c[i + 1] == '1')
			count++;
		i++;
	}
	close(fd);
	board->num_row = count + 1;
	board->board = malloc(sizeof(char *) * (count + 2));
	return (board->board);
}

static void	get_lines(int fd, t_board *board, char *line, int x)
{
	char	*last_line;
	int		len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	while (line && last_line[0] != '\n')
	{
		last_line = ft_strdup(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		free(last_line);
		board->board[x] = check_middle_line(line, board, len, board->board[x]);
		if (!board->board[x])
			kill_app(2, board->board, x);
		x++;
	}
	if (board->num_c < 1 || board->num_e != 1 || board->num_s != 1)
		kill_app(2, board->board, x);
	check_first_last_line(last_line, board->board[--x]);
	free(last_line);
	board->board[++x] = NULL;
	close(fd);
}

void	check_fd(int fd, t_board *board)
{
	char	*line;
	int		x;

	x = 0;
	board->num_c = 0;
	board->num_e = 0;
	board->num_s = 0;
	board->num_col = 0;
	line = get_next_line(fd);
	board->board[x] = check_first_last_line(line, board->board[x]);
	if (!board->board[x])
		kill_app(2, board->board, x);
	x++;
	get_lines(fd, board, line, x);
}
