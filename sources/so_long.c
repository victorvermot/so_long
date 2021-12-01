/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:52 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/01 10:26:42 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_board(char **board, int x)
{
	while (x <= 0)
	{
		free(board[x]);
		x--;
	}
	free(board);
}

void	kill_app(int opt, char **board, int x)
{
	if (opt == 0)
		ft_putstr_fd("Error\nCould not open the file provided", 1);
	else if (opt == 1)
	{
		ft_putstr_fd("You left the game, hope you liked it", 1);
		free_board(board, x);
	}
	else if (opt == 2)
	{
		ft_putstr_fd("Error\nThe file you provided is not valid", 1);
		free_board(board, x);
	}
	else if (opt == 3)
	{
		ft_putstr_fd("Well done, you beat the game", 1);
		free_board(board, x);
	}
	else if (opt == 4)
	{
		ft_putstr_fd("You got killed", 1);
		free_board(board, x);
	}
	exit(0);
}

static int	ft_kill(t_game *game)
{
	kill_app(1, game->board->board, game->board->num_row);
	return (1);
}

int	esc_key(int key, t_game *game)
{
	(void)key;
	kill_app(1, game->board->board, game->board->num_row);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;
	t_board	board;
	int		x;

	board.board = NULL;
	x = 0;
	if (argc != 2)
		kill_app(0, board.board, 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		kill_app(0, board.board, 0);
	board.board = get_num_lines(fd, &board);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		kill_app(0, board.board, 0);
	check_fd(fd, &board);
	generate_map(&board, &game);
	game.board = &board;
	mlx_string_put(game.mlx, game.win, 10, 10, 0xF, "Move counter : ");
	mlx_key_hook(game.win, get_key_input, &game);
	mlx_hook(game.win, 17, 0L, ft_kill, &game);
	mlx_loop(game.mlx);
	return (0);
}
