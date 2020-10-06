# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 11:25:01 by micarras          #+#    #+#              #
#    Updated: 2019/11/26 14:03:36 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
			ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_wchar.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
			ft_itoa.c ft_uitoa.c ft_modf.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_puthex.c	ft_putnbr_fd.c ft_lstadd_back.c \
			ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_malloc.c \
			ft_realloc.c ft_free.c ft_ishexdigit.c lcthw_darray_clear.c \
			ft_darray_alloc.c ft_darray_append.c ft_darray_clear.c \
			ft_darray_new.c ft_darray_overwrite.c ft_darray_popback.c \
			ft_darray_popindex.c ft_darray_printdata.c ft_darray_release.c \
			ft_darray_reserve.c ft_darray_resize.c ft_darray_string.c \
			ft_darray_substitute.c ft_darray_swap.c ft_darray_trim.c \
			ft_darray_last.c lcthw_darray_clear_destroy.c \
			lcthw_darray_contract.c lcthw_darray_create.c \
			lcthw_darray_destroy.c lcthw_darray_expand.c lcthw_darray_get.c \
			lcthw_darray_new.c lcthw_darray_pop.c lcthw_darray_push.c \
			lcthw_darray_remove.c lcthw_darray_resize.c lcthw_darray_set.c \
			lcthw_darray_popzero.c lcthw_darray_trim.c lcthw_darray_reserve.c \
			lcthw_pushhex.c ft_seek.c ft_round_base.c ft_intlen.c

OBJ		=	$(SRC:.c=.o)
CFLAGS	+=	-Wall -Wextra -Werror -I./
CC		=	gcc
.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):	$(OBJ)
			ar -rc $(NAME) $(OBJ)
all:		$(NAME)
clean:
			rm -f $(OBJ)
fclean:		clean
			rm -f $(NAME)
re:			fclean all
.PHONY:		all clean fclean re
