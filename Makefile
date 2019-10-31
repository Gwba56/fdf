# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbarach- <gbarach-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/27 11:22:32 by gbarach-          #+#    #+#              #
#    Updated: 2019/08/01 00:28:41 by gbarach-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAG = -lmlx -lm -lft
RM = rm -f
RMF = rm -rf

SRC_PATH = ./sources/
SRC =	check_data.c \
		check_file.c \
		convert_data.c \
		draw_line.c \
		draw.c \
		gradients.c \
		handle_error.c \
		hook.c \
		init_env.c \
		main.c \
		ui.c

HEADER_NAME = fdf.h
HEADER_PATH = ./includes/

LIBFT_PATH = ./libft/
LIBFT_NAME = libft.a

MLX_PATH = ./minilibx_macos/
MLX_NAME = mlx.a
MLX_FWK = -framework OpenGL -framework AppKit

OBJ_PATH = obj/
OBJ_LST = $(patsubst %.c, %.o, $(SRC))

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_LST))
HEADER = $(addprefix $(HEADER_PATH), $(HEADER_NAME))
LIBFT = $(addprefix $(LIBFT_PATH), $(LIBFT_NAME))
MLX = $(addprefix $(MLX_PATH), $(MLX_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_PATH) $(OBJ)
	@$(CC) $(CFLAGS) $(MLX_FLAG) -L $(LIBFT_PATH) -L $(MLX_PATH) $(MLX_FWK) -I $(HEADER_PATH) -I $(LIBFT_PATH) -I $(MLX_PATH) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c $(HEADER)
	$(CC) $(CFLAGS) -c -I $(HEADER_PATH) -I $(LIBFT_PATH) -I $(MLX_PATH) $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(MLX):
	@make -C $(MLX_PATH)

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean
	$(RMF) $(OBJ_PATH)

fclean: clean
	$(RM) $(MLX)
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all