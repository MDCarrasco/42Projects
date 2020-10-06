# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/22 09:49:36 by micarras          #+#    #+#              #
#    Updated: 2020/06/29 16:27:15 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s \
					ft_strdup.s
OBJS		=		$(SRCS:.s=.o)
BONUS_SRCS	=		ft_atoi_base_bonus.s ft_list_size_bonus.s \
					ft_list_push_front_bonus.s ft_list_remove_if_bonus.s \
					ft_list_sort_bonus.s
BONUS_OBJS	=		$(BONUS_SRCS:.s=.o)
NA			=		nasm
NA_FLAGS	=		-felf64
FLAGS		=		-Wall -Werror -Wextra
NAME		=		libasm.a
TEST		=		test
TEST_BONUS	=		test_bonus
TEST_FILES	=		./*.txt
%.o:				%.s
						$(NA) $(NA_FLAGS) $<
all:				$(NAME)
$(NAME):			$(OBJS)
						ar rcs $(NAME) $(OBJS)
clean:
						rm -rf $(OBJS) $(BONUS_OBJS) $(TEST_FILES)
fclean:				clean
						rm -rf $(NAME) $(BONUS) $(TEST) $(TEST_BONUS) $(TEST_FILES)
re:					fclean $(NAME)
test:				$(NAME)
						clang main.c -o $(TEST) -lc -lasm $(FLAGS) -L. -g3 -fsanitize=address
						./$(TEST) < Makefile
bonus:				$(OBJS) $(BONUS_OBJS)
						ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
test_bonus:			bonus
						clang main_bonus.c -o $(TEST_BONUS) -lc -lasm $(FLAGS) -L. -g3 -fsanitize=address
						./$(TEST_BONUS)
.PHONY:				clean fclean re test bonus test_bonus
