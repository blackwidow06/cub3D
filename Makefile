# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malavaud <malavaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/11 09:24:26 by malavaud          #+#    #+#              #
#    Updated: 2026/09/12 12:35:22 by malavaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D

CC          = cc

CFLAGS      = -Wall -Wextra -Werror

SRCS        = main.c \
			  init_structs.c \
			  parsing/parsing.c \
			  parsing/read_map.c \
			  parsing/checks.c \
			  error/exit_error.c \
              get_next_line/get_next_line.c \
              get_next_line/get_next_line_utils.c

OBJS        = $(SRCS:.c=.o)

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

%.o: %.c cub3D.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re