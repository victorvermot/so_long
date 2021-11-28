/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:22:14 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/28 16:37:24 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*add_img_to_window(t_game *game, char *path, int x, int y)
{
	t_image	new;

	new.relative_path = path;
	new.img = mlx_xpm_file_to_image(game->mlx, new.relative_path,
			&new.img_width, &new.img_height);
	mlx_put_image_to_window(game->mlx, game->win, new.img, x, y);
	return (new.img);
}

void	generate_images(t_game *game, char c, int x, int y)
{
	if (c == '1')
		add_img_to_window(game,
			"./sprites/wall.xpm", game->map_pos_x, game->map_pos_y);
	else if (c == '0' || c == 'P' || c == 'C')
		add_img_to_window(game,
			"./sprites/grass.xpm", game->map_pos_x, game->map_pos_y);
	else if (c == 'E')
		add_img_to_window(game,
			"./sprites/exit.xpm", game->map_pos_x, game->map_pos_y);
	if (c == 'P')
	{
		add_img_to_window(game,
			"./sprites/ness.xpm", game->map_pos_x + 10, game->map_pos_y + 20);
		game->player_pos_x = x;
		game->player_pos_y = y;
	}
	else if (c == 'C')
		add_img_to_window(game,
			"./sprites/coll.xpm", game->map_pos_x, game->map_pos_y + 20);
	game->map_pos_x += 35;
}

void	generate_new_map(t_board *board, t_game	*game)
{
	int	i;
	int	j;

	game->map_pos_x = 0;
	game->map_pos_y = 0;
	i = 0;
	j = 0;
	while (board->board[i])
	{
		while (board->board[i][j])
		{
			generate_images(game, board->board[i][j], i, j);
			j++;
		}
		j = 0;
		game->map_pos_x = 0;
		game->map_pos_y += 57;
		i++;
	}
}

void	generate_map(t_board *board, t_game	*game)
{
	int	i;
	int	j;

	game->map_pos_x = 0;
	game->map_pos_y = 0;
	i = 0;
	j = 0;
	while (board->board[i])
	{
		while (board->board[i][j])
		{
			generate_images(game, board->board[i][j], i, j);
			j++;
		}
		j = 0;
		game->map_pos_x = 0;
		game->map_pos_y += 57;
		i++;
	}
}
