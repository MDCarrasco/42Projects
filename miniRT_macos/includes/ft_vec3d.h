/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 22:20:05 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:25:53 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VEC3D_H
# define FT_VEC3D_H

typedef struct			s_vec3d
{
	double				x;
	double				y;
	double				z;
}						t_vec3d;

t_vec3d					v3d_defaultcon(void);
t_vec3d					v3d_singlecon(double x);
t_vec3d					v3d_fullcon(double x, double y, double z);
t_vec3d					v3d_divdouble(t_vec3d v, double r);
t_vec3d					v3d_divv3d(t_vec3d v, t_vec3d vv);
double					v3d_dot(t_vec3d a, t_vec3d b);
t_vec3d					v3d_inverted(t_vec3d v);
double					v3d_magnitude(t_vec3d v);
t_vec3d					v3d_minusv3d(t_vec3d v, t_vec3d vv);
double					v3d_norm(t_vec3d v);
t_vec3d					v3d_plusv3d(t_vec3d v, t_vec3d vv);
t_vec3d					v3d_timesdouble(t_vec3d v, double r);
t_vec3d					v3d_timesv3d(t_vec3d v, t_vec3d vv);
t_vec3d					v3d_unit(t_vec3d v);
t_vec3d					v3d_cross(t_vec3d a, t_vec3d b);
t_vec3d					v3d_forward(void);
t_vec3d					v3d_up(void);
t_vec3d					v3d_right(void);

extern const t_vec3d	g_v3d_forward;
extern const t_vec3d	g_v3d_up;
extern const t_vec3d	g_v3d_right;

#endif
