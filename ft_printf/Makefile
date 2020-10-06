# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 17:14:49 by micarras          #+#    #+#              #
#    Updated: 2019/11/18 10:39:55 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBFT	=	./libft/
LIBFT_A =	libft.a
LIBFT_H =	-I libft/
SRC		=	ft_printf.c ft_vprintf.c ft_vasprintf.c ft_convert.c \
			ft_convert_numeric_1.c ft_convert_numeric_2.c \
			ft_convert_numeric_3.c ft_convert_char.c ft_convert_double_1.c \
			ft_convert_double_2.c ft_populate.c

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I./libft
CC = gcc
.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp $(LIBFT)$(LIBFT_A) .
			mv $(LIBFT_A) $(NAME)
			ar -rc $(NAME) $(OBJ)
			ranlib $(NAME)
all:		$(NAME)
clean:
			rm -f $(OBJ)
			make -C $(LIBFT) clean
fclean:		clean
			rm -f $(NAME)
			make -C $(LIBFT) fclean
re:			fclean all
.PHONY:		all clean fclean re
