/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:06:02 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/29 19:53:44 by vvermot-         ###   ########.fr       */
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
		update_count(game);
		return (1);
	}
	else if (c == 'E')
	{
		if (game->can_exit)
			kill_app(3, game->board->board, game->board->num_row);
		return (0);
	}
	else if (c == 'X')
		kill_app(4, game->board->board, game->board->num_row);
	update_count(game);
	return (1);
}

static void	check_up_down(t_game *game, int dir)
{
	if (dir == UP)
	{
		game->board->board[game->player_pos_x - 1][game->player_pos_y] = 'P';
		game->board->board[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_x -= 1;
	}
	else if (dir == DOWN)
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
	if (dir == RIGHT)
	{
		game->board->board[game->player_pos_x][game->player_pos_y + 1] = 'P';
		game->board->board[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_y += 1;
	}
	else if (dir == LEFT)
	{
		game->board->board[game->player_pos_x][game->player_pos_y - 1] = 'P';
		game->board->board[game->player_pos_x][game->player_pos_y] = '0';
		game->player_pos_y -= 1;
	}
	game->map_pos_x = game->player_pos_y * 35;
	game->map_pos_y = game->player_pos_x * 57;
	generate_player(game, dir);
}

static int	player_movements(int key, t_game *game)
{
	if (key == UP)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x - 1][game->player_pos_y]))
			switch_tiles(game, UP);
	}
	else if (key == DOWN)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x + 1][game->player_pos_y]))
			switch_tiles(game, DOWN);
	}
	else if (key == RIGHT)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x][game->player_pos_y + 1]))
			switch_tiles(game, RIGHT);
	}
	else if (key == LEFT)
	{
		if (check_next_tile(game,
				game->board->board[game->player_pos_x][game->player_pos_y - 1]))
			switch_tiles(game, LEFT);
	}
	return (0);
}

int	get_key_input(int key, t_game *game)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	{
		player_movements(key, game);
		if (game->is_enenmy)
			enemy_movements(key, game);
	}
	else if (key == ESC)
		esc_key(key, game);
	if (game->can_exit == 1)
	{
		game->map_pos_x = game->exit_pos_x * 57;
		game->map_pos_y = game->exit_pos_y * 35;
		add_img_to_window(game, "./sprites/exit_o.xpm",
			game->map_pos_y, game->map_pos_x);
	}
	return (0);
}
