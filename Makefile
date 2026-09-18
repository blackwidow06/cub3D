# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/11 09:24:26 by malavaud          #+#    #+#              #
#    Updated: 2026/09/17 17:23:56 by mrojouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = cub3D

CC          = cc

CFLAGS      = -Wall -Wextra -Werror -g

SRCS        = main.c \
              parsing/check_textures.c \
              parsing/read_map.c \
              parsing/read_map_grid.c \
			  parsing/utils.c \
              parsing/check_map_utils.c \
              parsing/check_map_walls.c \
              parsing/parsing.c \
              parsing/check_colors.c \
			  parsing/parse_player.c \
			  parsing/parse_color.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c \
			  init_struct.c \
			  error.c \
			  game/game.c \
			  game/draw_map.c \
			  game/movement.c \

OBJ_DIR     = obj

OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

MLX_DIR     = minilibx-linux

MLX_LIB     = $(MLX_DIR)/libmlx.a

LIBFT_DIR   = libft

LIBFT_LIB   = $(LIBFT_DIR)/libft.a

MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES    = -I. -I$(MLX_DIR) -Iget_next_line -I$(LIBFT_DIR)

RM          = rm -f


all: $(NAME)


$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) -o $(NAME)


$(MLX_LIB):
	make -C $(MLX_DIR)


$(LIBFT_LIB):
	make -C $(LIBFT_DIR)


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	$(RM) -r $(OBJ_DIR)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean


fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean


re: fclean all


.PHONY: all clean fclean re