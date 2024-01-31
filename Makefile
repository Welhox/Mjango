# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clundber <clundber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 11:59:53 by clundber          #+#    #+#              #
#    Updated: 2024/01/31 17:06:08 by clundber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_END=\033[0m

ifeq ($(shell uname), Linux)
	INCLUDES = -I/usr/include -Imlx
else
	INCLUDES = -I/opt/X11/include -Imlx
endif

# ------------ PROJECT -------#
NAME = so_long
LIBFTNAME = libft.a

# ------------ DIRECTORIES ---#
LIBFT_DIR = ./libft
SRCS_DIR = ./srcs
OBJ_DIR = ./srcs/temp
MLX_DIR = ./mlx

#------------- SOURCE FILES ------#
CFILES = $(SRCS_DIR)/so_long.c
OFILES = $(CFILES:.c=.o)
MLX_LIB = $(MLX_DIR)/libmlx_$(UNAME).a

#--------- FLAGS ----------#
CC = @cc
CFLAGS = -Wall -Wextra -Werror -g -I includes
ifeq ($(shell uname), Linux)
	MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
else
	MLX_FLAGS = -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

all: $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OFILES)
	@echo "$(COLOUR_BLUE)compiling $(NAME)$(COLOUR_END)"
	@make -C libft
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT_DIR)/$(LIBFTNAME) -o $(NAME) $(MLX_FLAGS)
	@mkdir -p $(OBJ_DIR)
	@mv $(OFILES) $(OBJ_DIR)
	@echo "$(COLOUR_GREEN)$(NAME) compiled successfully$(COLOUR_END)"

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@echo "$(COLOUR_GREEN)cleaning $(NAME)$(COLOUR_END)"
	@rm -r -f $(OBJ_DIR) 
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME) 
	@rm -f libft/libft.a

re: fclean $(NAME) 

.PHONY: all clean fclean re