/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:52 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/28 12:38:40 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	kill_app(int opt, char **board, int x)
{
	if (opt == 0)
		ft_putstr_fd("Error\nCould not open the file provided", 1);
	else if (opt == 1)
		ft_putstr_fd("You left the game, hope you liked it", 1);
	else if (opt == 2)
	{
		ft_putstr_fd("Error\nThe file you provided is not valid", 1);
		while (x <= 0)
		{
			free(board[x]);
			x--;
		}
		free(board);
	}
	else if (opt == 3)
	{
		ft_putstr_fd("Well done, you beat the game", 1);
		while (x <= 0)
		{	
			free(board[x]);
			x--;
		}
		free(board);
	}
	exit(0);
}

int	ft_kill(t_game *game)
{
	kill_app(2, game->board->board, game->board->num_row);
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
	board.board = get_num_lines(fd, &board);
	fd = open(argv[1], O_RDONLY);
	check_fd(fd, &board);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			board.num_col * 35, board.num_row * 57, "mlx 42");
	game.can_exit = 0;
	game.move_count = 0;
	generate_map(&board, &game);
	game.board = &board;
	mlx_key_hook(game.win, player_movements, &game);
	mlx_hook(game.win, 17, 0L, ft_kill, &game);
	mlx_loop(game.mlx);
	return (0);
}
