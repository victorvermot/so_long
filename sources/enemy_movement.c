/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:27:41 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/29 18:25:12 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	add_enemy_sprite(t_game *game, int go_right)
{
	if (go_right)
	{
		add_img_to_window(game, "./sprites/e_r.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
	}
	else if (!go_right)
	{
		add_img_to_window(game, "./sprites/e_l.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
	}
}

static void	switch_tiles_e(t_game *game, int *go_right)
{
	game->map_pos_x = game->e_pos_y * 35;
	game->map_pos_y = game->e_pos_x * 57;
	generate_images(game, '0', game->e_pos_x, game->e_pos_y);
	if (*go_right)
	{
		if (game->board->board[game->e_pos_x][game->e_pos_y + 1] == 'P')
			kill_app(4, game->board->board, game->board->num_row);
		game->board->board[game->e_pos_x][game->e_pos_y + 1] = 'X';
		game->board->board[game->e_pos_x][game->e_pos_y] = '0';
		game->e_pos_y += 1;
	}
	else if (!*go_right)
	{
		if (game->board->board[game->e_pos_x][game->e_pos_y - 1] == 'P')
			kill_app(4, game->board->board, game->board->num_row);
		game->board->board[game->e_pos_x][game->e_pos_y - 1] = 'X';
		game->board->board[game->e_pos_x][game->e_pos_y] = '0';
		game->e_pos_y -= 1;
	}
	game->map_pos_x = game->e_pos_y * 35;
	game->map_pos_y = game->e_pos_x * 57;
	add_enemy_sprite(game, *go_right);
}

static int	check_next_tile_e(t_game *game, int *right_ok, char c)
{
	if ((c == '1' || c == 'E' || c == 'C') && !*right_ok)
	{
		*right_ok = 1;
		return (1);
	}
	else if ((c == '1' || c == 'E' || c == 'C') && *right_ok)
	{
		*right_ok = 0;
		return (1);
	}
	else if (c == 'P')
	{
		kill_app(4, game->board->board, game->board->num_row);
		return (1);
	}
	return (1);
}

int	enemy_movements(int key, t_game *game)
{
	int static	go_right = 0;

	(void)key;
	if (go_right)
	{
		check_next_tile_e(game, &go_right,
			game->board->board[game->e_pos_x][game->e_pos_y + 1]);
		switch_tiles_e(game, &go_right);
	}
	else if (!go_right)
	{
		check_next_tile_e(game, &go_right,
			game->board->board[game->e_pos_x][game->e_pos_y - 1]);
		switch_tiles_e(game, &go_right);
	}
	return (0);
}
