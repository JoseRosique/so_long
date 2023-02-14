# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joslopez <joslopez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 11:53:49 by joslopez          #+#    #+#              #
#    Updated: 2022/09/13 18:19:37 by joslopez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := game/*.c
GETNEXTLINE := get_next_line/*c
LIBRARY := -LMLX42 -lmlx -framework OpenGL -framework AppKit
MLX42 := MLX42/

all:
	make -C $(MLX42)
	$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(LIBRARY) -o $(NAME)

clean:

fclean: clean
		make clean -C $(MLX42)
		rm -rf $(NAME)

re: fclean all
