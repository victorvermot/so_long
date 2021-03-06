/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvermot- <vvermot-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:27:53 by vvermot-          #+#    #+#             */
/*   Updated: 2021/11/29 19:56:29 by vvermot-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libraries/libft/libft.h"
# include "../libraries/mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

# define BUFFER_SIZE 1

enum e_movement_keys {
	UP = 13,
	DOWN = 1,
	LEFT = 0,
	RIGHT = 2,
	ESC = 53
};

typedef struct s_image {
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_board {
	int		num_s;
	int		num_e;
	int		num_c;
	char	**board;
	int		num_col;
	int		num_row;
}				t_board;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		map_pos_x;
	int		map_pos_y;
	int		exit_pos_x;
	int		exit_pos_y;
	int		player_pos_x;
	int		player_pos_y;
	int		e_pos_x;
	int		e_pos_y;
	int		can_exit;
	int		move_count;
	int		is_enenmy;
	t_board	*board;
	t_image	img;
}				t_game;

void	check_fd(int fd, t_board *board);
char	*get_next_line(int fd);
void	kill_app(int opt, char **board, int x);
char	**get_num_lines(int fd, t_board *board);
void	generate_map(t_board *board, t_game	*vars);
void	*add_img_to_window(t_game *game, char *path, int x, int y);
int		get_key_input(int key, t_game *game);
void	generate_images(t_game *game, char c, int x, int y);
void	generate_new_map(t_board *board, t_game	*game);
int		esc_key(int key, t_game *game);
void	generate_player(t_game *game, int dir);
int		enemy_movements(int key, t_game *game);
void	update_count(t_game *game);

#endif