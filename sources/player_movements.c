/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:06:02 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/28 16:17:00 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_next_tile(t_game *game, char c)
{
	if (c == '1')
		return (0);
	else if (c == 'C')
	{
		game->board->num_c -= 1;
		if (game->board->num_c == 0)
			game->can_exit = 1;
		game->move_count += 1;
		printf("You moved %d times\n", game->move_count);
		return (1);
	}
	else if (c == 'E')
	{
		if (game->can_exit)
			kill_app(3, game->board->board, game->board->num_row);
		else
			return (0);
	}
	game->move_count += 1;
	printf("You moved %d times\n", game->move_count);
	return (1);
}

static void	check_up_down(t_game *game, int dir)
{
	if (dir == 13)
	{
		game->board->board[game->player_pos_x - 1][game->player_pos_y] = 'P';
		game->board->board[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_x -= 1;
	}
	else if (dir == 1)
	{
		game->board->board[game->player_pos_x + 1][game->player_pos_y] = 'P';
		game->board->board[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_x += 1;
	}
}

static void	switch_tiles(t_game *game, int dir)
{
	game->map_pos_x = game->player_pos_y * 35;
	game->map_pos_y = game->player_pos_x * 57;
	generate_images(game, '0', game->player_pos_x, game->player_pos_y);
	check_up_down(game, dir);
	if (dir == 2)
	{
		game->board->board[game->player_pos_x][game->player_pos_y + 1] = 'P';
		game->board->board[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_y += 1;
	}
	else if (dir == 0)
	{
		game->board->board[game->player_pos_x][game->player_pos_y - 1] = 'P';
		game->board->board[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_y -= 1;
	}
	game->map_pos_x = game->player_pos_y * 35;
	game->map_pos_y = game->player_pos_x * 57;
	generate_images(game, 'P', game->player_pos_x, game->player_pos_y);
}

static int	player_movements(int key, t_game *game)
{
	if (key == 13)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x - 1][game->player_pos_y]))
			switch_tiles(game, 13);
	}
	else if (key == 1)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x + 1][game->player_pos_y]))
			switch_tiles(game, 1);
	}
	else if (key == 2)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x][game->player_pos_y + 1]))
			switch_tiles(game, 2);
	}
	else if (key == 0)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x][game->player_pos_y - 1]))
			switch_tiles(game, 0);
	}
	return (0);
}

int	get_key_input(int key, t_game *game)
{
	if (key == 13 || key == 1 || key == 2 || key == 0)
		player_movements(key, game);
	else if (key == 53)
		esc_key(key, game);
	return (0);
}