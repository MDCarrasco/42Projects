# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 11:25:01 by micarras          #+#    #+#              #
#    Updated: 2020/06/15 16:52:50 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRC		=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isinset.c ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c \
			ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
			ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_wchar.c \
			ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
			ft_itoa.c ft_uitoa.c ft_modf.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_puthex.c	ft_putnbr_fd.c ft_lstadd_back.c \
			ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_malloc.c \
			ft_realloc.c ft_free.c ft_ishexdigit.c \
			ft_seek.c ft_round_base.c \
			ft_mat4_addv.c ft_mat4_angles.c \
			ft_mat4_cons.c ft_mat4_identity.c ft_mat4_inverse.c \
			ft_mat4_look_vec.c ft_mat4_lookat.c ft_mat4_mul.c \
			ft_mat4_mul_rbx.c ft_mat4_mulv_dir.c ft_mat4_pos.c \
			ft_mat4_right_vec.c ft_mat4_up_vec.c \
			ft_vec3d_cons.c ft_vec3d_divx.c ft_vec3d_dot.c ft_vec3d_invert.c \
			ft_vec3d_magnitude.c ft_vec3d_minus.c ft_vec3d_norm.c \
			ft_vec3d_plus.c ft_vec3d_timesx.c ft_vec3d_unit.c ft_vec3d_cross.c \
			ft_vec3d_forward.c ft_vec3d_up.c ft_vec3d_right.c \
			ft_vector_new.c ft_vector_destroy.c ft_vector_get.c \
			ft_vector_getr.c ft_vector_pop.c ft_vector_push.c \
			ft_vector_resize.c ft_vector_set.c ft_vector_with_capacity.c

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
