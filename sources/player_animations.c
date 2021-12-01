/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:36:25 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/29 19:55:11 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_up(t_game *game, char *state)
{
	if (*state == 'u')
	{
		add_img_to_window(game,
			"./sprites/ness_b2.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = '0';
	}
	else
	{
		add_img_to_window(game,
			"./sprites/ness_b.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = 'u';
	}
}

static void	player_down(t_game *game, char *state)
{
	if (*state == 'd')
	{
		add_img_to_window(game,
			"./sprites/ness_2.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = '0';
	}
	else
	{
		add_img_to_window(game,
			"./sprites/ness.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = 'd';
	}
}

static void	player_right(t_game *game, char *state)
{
	if (*state == 'r')
	{
		add_img_to_window(game,
			"./sprites/ness_r2.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = '0';
	}
	else
	{
		add_img_to_window(game,
			"./sprites/ness_r.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = 'r';
	}
}

static void	player_left(t_game *game, char *state)
{
	if (*state == 'l')
	{
		add_img_to_window(game,
			"./sprites/ness_l2.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = '0';
	}
	else
	{
		add_img_to_window(game,
			"./sprites/ness_l.xpm",
			game->map_pos_x + 10, game->map_pos_y + 20);
		*state = 'l';
	}
}

void	generate_player(t_game *game, int dir)
{
	static char	state;

	if (dir == LEFT)
		player_left(game, &state);
	else if (dir == RIGHT)
		player_right(game, &state);
	else if (dir == DOWN)
		player_down(game, &state);
	else if (dir == UP)
		player_up(game, &state);
	game->map_pos_x += 35;
}
