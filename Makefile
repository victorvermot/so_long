SRCS	= 	${addprefix sources/, so_long.c map_checks.c map_generator.c player_movements.c}	\
			${addprefix get_next_line/, get_next_line.c	get_next_line_utils.c}

NAME		= 	so_long
FLGS		= 	-Wall -Wextra -Werror
OBJS		= 	${SRCS:.c=.o}
GCC			= 	gcc
RM			= 	rm -f
MLX_PATH	= 	./libraries/mlx/
LBFT_PATH	= 	./libraries/libft/
FRAMLIBS	= 	-L ${LBFT_PATH} -lft -L ${MLX_PATH} -lmlx -framework OpenGL -framework AppKit

all:		${LIBFT} ${MLX} ${NAME}

.c.o:
			${GCC} ${FLGS} -Imlx -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${GCC} ${FLGS} -I ${MLX_PATH} -I ${LBFT_PATH} -o ${NAME} ${OBJS} ${FRAMLIBS}

${LIBFT}:
			@make -C ${LBFT_PATH}

${MLX}:
			@make -C ${MLX_PATH}

fclean:		clean
			${RM} ${NAME}

clean:
			${RM} ${OBJS}
			@make -C $(LBFT_PATH) clean
			@make -C $(MLX_PATH) clean

re:			fclean all

.PHONY:		all fclean clean re