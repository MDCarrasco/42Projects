# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: micarras <micarras@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 20:09:13 by micarras          #+#    #+#              #
#    Updated: 2020/10/12 12:54:34 by micarras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			clang
FLAGS =			-Wall -Wextra -Werror -O3 -g3 -fsanitize=address
CONFIG_FLAGS =  -D IS_BONUS=0 -D THREAD_COUNT=1
RM =			rm -rf
DIR_SAVES =		./save/
DIR_HEADERS =	./includes/
DIR_SRCS =		./srcs/
DIR_OBJS =		./
LIBMLX =		libmlx.dylib
LIBFT =			libft.a
#SAVE =			-fsanitize=address
SRC =			main.c \
				rendering/render.c \
				rendering/canvas_put_pixel.c \
				rendering/render_pixel.c \
				rendering/renderer_destroy.c \
				rendering/screen_ray.c \
				rendering/setup_renderer.c \
				color/color.c \
				export/bmp.c \
				scene/scene.c \
				scene/objects/ray.c \
				scene/objects/sphere.c \
				scene/objects/plane.c \
				scene/objects/square.c \
				scene/objects/triangle.c \
				scene/objects/cylinder.c \
				interaction/change_obj_pos.c \
				interaction/change_obj_rot.c \
				interaction/change_obj_size.c \
				interaction/change_scale.c \
				interaction/decrease_fov.c \
				interaction/increase_fov.c \
				interaction/exit_program.c \
				interaction/move_backward.c \
				interaction/move_down_world.c \
				interaction/move_forward.c \
				interaction/move_left.c \
				interaction/move_right.c \
				interaction/move_up_world.c \
				interaction/next_camera.c \
				interaction/prev_camera.c \
				interaction/obj_pos_addx.c \
				interaction/obj_pos_addy.c \
				interaction/obj_pos_addz.c \
				interaction/obj_pos_subx.c \
				interaction/obj_pos_suby.c \
				interaction/obj_pos_subz.c \
				interaction/obj_rot_addx.c \
				interaction/obj_rot_addy.c \
				interaction/obj_rot_addz.c \
				interaction/obj_rot_subx.c \
				interaction/obj_rot_suby.c \
				interaction/obj_rot_subz.c \
				interaction/pitch_up.c \
				interaction/pitch_down.c \
				interaction/roll_left.c \
				interaction/roll_right.c \
				interaction/rotate_left.c \
				interaction/rotate_right.c \
				parser/cb_ambient.c \
				parser/cb_camera.c \
				parser/cb_color.c \
				parser/cb_cylinder.c \
				parser/cb_light.c \
				parser/cb_plane.c \
				parser/cb_resolution.c \
				parser/cb_scene.c \
				parser/cb_sphere.c \
				parser/cb_square.c \
				parser/cb_triangle.c \
				parser/cb_vector.c \
				parser/expect.c \
				parser/parse_from_file.c \
				parser/skip_atleast.c \
				parser/take_double.c \
				parser/take_number.c \
				dstring/dstring_fullcon.c \
				dstring/dstring_push.c \
				dstring/dstring_pushn.c \
				misc/solve_quad.c \
				misc/degrad.c \
				error/error.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
#COMPIL =		$(FLAGS) $(SAVE)
OBJS =			$(SRCS:.c=.o)
NAME =			miniRT
all:			$(NAME)
$(NAME) :		$(OBJS)
				@make -C ./minilibx_mms
				@make -C ./libft
				@mv ./minilibx_mms/libmlx.dylib libmlx.dylib
				@mv ./libft/libft.a libft.a
				#$(CC) $(FLAGS) -o $(NAME) -I $(DIR_HEADERS) $(OBJS) $(LIBFT) $(LIBMLX) -lm -pthread -lX11 -lXext
				$(CC) $(FLAGS) -o $(NAME) -I $(DIR_HEADERS) $(OBJS) $(LIBFT) $(LIBMLX) -lm -pthread
%.o: %.c
				@gcc $(FLAGS) $(CONFIG_FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"
bonus:			CONFIG_FLAGS = -D IS_BONUS=1 -D THREAD_COUNT=12
bonus:			all
norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)
clean:
				$(RM) $(OBJS)
fclean:				clean
				@make clean -C ./minilibx_mms
				@make clean -C ./libft
				$(RM) libmlx.dylib
				$(RM) libft.a
				$(RM) $(DIR_SAVES)*
				$(RM) $(NAME)
re:				fclean all
rebonus:		fclean bonus
.PHONY:			all, clean, fclean, re, bonus
