# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguerin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/20 18:39:57 by arguerin          #+#    #+#              #
#    Updated: 2018/03/20 18:40:08 by arguerin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRCS = bug.c \
	draw.c \
	fractol.c \
	option_julia.c \
	option.c \
	screen.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C minilibx_macos/ clean
	@make -C libft/ && make -C minilibx_macos/
	@gcc -Wall -Wextra -Werror -I libft -I minilibx_macos/ -c $(SRCS)
	@gcc -o $(NAME) $(OBJ) -framework OpenGL -framework AppKit libft/libft.a minilibx_macos/libmlx.a


clean :
	@rm -f $(OBJ)
	@make -C libft/ fclean && make -C minilibx_macos/ clean

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: clean fclean re all
