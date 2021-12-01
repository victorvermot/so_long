/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:22:14 by vvermot-          #+#    #+#             */
/*   Updated: 2021/12/01 10:26:42 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_count(t_game *game)
{
	game->move_count += 1;
	add_img_to_window(game, "./sprites/wall.xpm", 3 * 35, 0);
	mlx_string_put(game->mlx, game->win, 120, 10, 0xF,
		ft_itoa(game->move_count));
}

void	*add_img_to_window(t_game *game, char *path, int x, int y)
{
	t_image	new;

	new.relative_path = path;
	new.img = mlx_xpm_file_to_image(game->mlx, new.relative_path,
			&new.img_width, &new.img_height);
	mlx_put_image_to_window(game->mlx, game->win, new.img, x, y);
	return (new.img);
}

void	additional_checks(t_game *game, char c, int x, int y)
{
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
	else if (c == 'X')
	{
		add_img_to_window(game,
			"./sprites/e_l.xpm", game->map_pos_x + 10, game->map_pos_y + 20);
		game->e_pos_x = x;
		game->e_pos_y = y;
		game->is_enenmy = 1;
	}
}

void	generate_images(t_game *game, char c, int x, int y)
{
	if (c == '1')
		add_img_to_window(game,
			"./sprites/wall.xpm", game->map_pos_x, game->map_pos_y);
	else if (c == '0' || c == 'P' || c == 'C' || c == 'X')
		add_img_to_window(game,
			"./sprites/grass.xpm", game->map_pos_x, game->map_pos_y);
	else if (c == 'E')
	{
		add_img_to_window(game,
			"./sprites/exit.xpm", game->map_pos_x, game->map_pos_y);
		game->exit_pos_x = x;
		game->exit_pos_y = y;
	}
	additional_checks(game, c, x, y);
	game->map_pos_x += 35;
}

void	generate_map(t_board *board, t_game	*game)
{
	int	i;
	int	j;

	game->is_enenmy = 0;
	game->map_pos_x = 0;
	game->map_pos_y = 0;
	i = 0;
	j = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx,
			board->num_col * 35, board->num_row * 57, "mlx 42");
	game->can_exit = 0;
	game->move_count = 0;
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
