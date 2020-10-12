/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:14:18 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 15:54:20 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAT4_H
# define FT_MAT4_H

# include <ft_vec3d.h>

# define EPSILON 1e-6

typedef struct	s_mat4 {
	double		inner[4][4];
}				t_mat4;

t_mat4			m4_defaultcon(void);
t_mat4			m4_identity(void);
t_mat4			m4_fullcon(t_vec3d right, t_vec3d up,
				t_vec3d look, t_vec3d pos);
t_vec3d			m4_pos(t_mat4 m);
t_mat4			m4_angles(double x, double y, double z);
t_mat4			m4_lookat(t_vec3d position, t_vec3d target);
t_mat4			m4_from_v3d(t_vec3d position);
t_mat4			m4_mul(t_mat4 m, t_mat4 mm);
t_mat4			m4_mul_rbx(t_mat4 m, t_vec3d v);
t_vec3d			m4_look_vec(t_mat4 m);
t_vec3d			m4_right_vec(t_mat4 m);
t_vec3d			m4_up_vec(t_mat4 m);
t_vec3d			m4_mulv_dir(t_mat4 m, t_vec3d dir);
t_mat4			m4_inverse(t_mat4 m);
t_mat4			m4_addv(t_mat4 m, t_vec3d v);

#endif
