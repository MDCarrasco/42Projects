/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:45:41 by micarras          #+#    #+#             */
/*   Updated: 2020/10/12 13:17:41 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERACTION_H
# define INTERACTION_H

# include <rendering.h>
# include <ft_mat4.h>

# define CAM_SPEED 0.5
# define CAM_ROT_SPEED 5.0
# define CAM_FOV_STEP 2.0
# define RESIZE_STEP 0.5
# define ROT_DEGREES 90.0
# define TRANSLATE_STEP 1.0

typedef enum	e_keycode
{
	Escape = 0x35,
	Q = 0x0C,
	E = 0x0E,
	W = 0x0D,
	S = 0x01,
	A = 0x00,
	D = 0x02,
	Left = 0x7B,
	Right = 0x7C,
	Up = 0x7E,
	Down = 0x7D,
	Minus = 0x1B,
	Plus = 0x18,
	Comma = 0x2B,
	Dot = 0x2F,
	F1 = 0x7A,
	F2 = 0x78,
	F3 = 0x63,
	F4 = 0x76,
	F5 = 0x60,
	F6 = 0x61,
	R = 0x0F,
	T = 0x11,
	Y = 0x10,
	F = 0x04,
	G = 0x05,
	H = 0x03,
	U = 0x20,
	I = 0x22,
	O = 0x1F,
	J = 0x26,
	K = 0x28,
	L = 0x25,
	None = -1
}				t_keycode;

typedef struct	s_key_pair
{
	t_keycode	keycode;
	void		(*action)(t_rendering_obj *);
}				t_key_pair;

void			move_forward(t_rendering_obj *renderer);
void			move_backward(t_rendering_obj *renderer);
void			move_left(t_rendering_obj *renderer);
void			move_right(t_rendering_obj *renderer);
void			move_up_world(t_rendering_obj *renderer);
void			move_down_world(t_rendering_obj *renderer);
void			increase_fov(t_rendering_obj *renderer);
void			decrease_fov(t_rendering_obj *renderer);
void			rotate_left(t_rendering_obj *renderer);
void			rotate_right(t_rendering_obj *renderer);
void			pitch_up(t_rendering_obj *renderer);
void			pitch_down(t_rendering_obj *renderer);
void			roll_left(t_rendering_obj *renderer);
void			roll_right(t_rendering_obj *renderer);
void			exit_program(t_rendering_obj *renderer);
void			next_camera(t_rendering_obj *renderer);
void			prev_camera(t_rendering_obj *renderer);
void			increase_obj_size(t_rendering_obj *renderer);
void			decrease_obj_size(t_rendering_obj *renderer);
void			scale_up(t_rendering_obj *renderer);
void			scale_down(t_rendering_obj *renderer);
int				exit_program_i(t_rendering_obj *renderer);
void			change_obj_pos(t_rendering_obj *renderer, t_vec3d offset);
void			change_obj_rot(t_rendering_obj *renderer, t_vec3d offset);
void			obj_pos_addx(t_rendering_obj *renderer);
void			obj_pos_subx(t_rendering_obj *renderer);
void			obj_pos_addy(t_rendering_obj *renderer);
void			obj_pos_suby(t_rendering_obj *renderer);
void			obj_pos_addz(t_rendering_obj *renderer);
void			obj_pos_subz(t_rendering_obj *renderer);
void			obj_rot_addx(t_rendering_obj *renderer);
void			obj_rot_subx(t_rendering_obj *renderer);
void			obj_rot_addy(t_rendering_obj *renderer);
void			obj_rot_suby(t_rendering_obj *renderer);
void			obj_rot_addz(t_rendering_obj *renderer);
void			obj_rot_subz(t_rendering_obj *renderer);

#endif
