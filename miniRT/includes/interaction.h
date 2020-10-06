/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:45:41 by micarras          #+#    #+#             */
/*   Updated: 2020/06/17 10:49:52 by micarras         ###   ########.fr       */
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
	Escape = 0xFF1B,
	Q = 0x071,
	E = 0x065,
	W = 0x077,
	S = 0x073,
	A = 0x061,
	D = 0x064,
	Left = 0xFF51,
	Right = 0xFF53,
	Up = 0xFF52,
	Down = 0xFF54,
	Minus = 0x02D,
	Plus = 0x03D,
	Comma = 0x02C,
	Dot = 0x02E,
	F1 = 0xFFBE,
	F2 = 0xFFBF,
	F3 = 0xFFC0,
	F4 = 0xFFC1,
	F5 = 0xFFC2,
	F6 = 0xFFC3,
	R = 0x072,
	T = 0x074,
	Y = 0x079,
	F = 0x066,
	G = 0x067,
	H = 0x068,
	U = 0x075,
	I = 0x069,
	O = 0x06F,
	J = 0x06A,
	K = 0x06B,
	L = 0x06C,
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
