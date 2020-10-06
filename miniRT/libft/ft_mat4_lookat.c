/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_lookat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:46:21 by micarras          #+#    #+#             */
/*   Updated: 2020/06/17 10:23:44 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <ft_mat4.h>

static t_mat4
	quat_to_matrix(double w, double x, double y, double z)
{
	t_vec3d			m0;
	t_vec3d			m1;
	t_vec3d			m2;

	m0 = v3d_fullcon(1.0 - 2.0 * (y * y + z * z), \
		2.0 * (x * y - z * w), 2.0 * (x * z + y * w));
	m1 = v3d_fullcon(2.0 * (x * y + z * w), 1.0 - 2.0 * (x * x + z * z), \
		2.0 * (y * z - x * w));
	m2 = v3d_fullcon(2.0 * (x * z - y * w), 2.0 * (y * z + x * w), \
		1.0 - 2.0 * (x * x + y * y));
	return (m4_fullcon(m0, m1, m2, v3d_defaultcon()));
}

static t_mat4
	lookat_by_matrix(t_vec3d position, t_vec3d target)
{
	t_vec3d	forward;
	t_vec3d	right;
	t_vec3d	up;

	forward = v3d_unit(v3d_minusv3d(position, target));
	right = v3d_cross(g_v3d_up, forward);
	up = v3d_cross(forward, right);
	return (m4_fullcon(right, up, forward, position));
}

static t_mat4
	lookat_by_quat(t_vec3d position, t_vec3d target)
{
	double			angle;
	double			normal;
	t_vec3d			axis;
	t_vec3d			to;
	t_mat4			from_quat;

	to = v3d_unit(v3d_minusv3d(target, position));
	angle = acos(v3d_dot(g_v3d_forward, to));
	axis = v3d_cross(g_v3d_forward, to);
	axis = v3d_unit(axis);
	if (v3d_norm(axis) > -EPSILON && v3d_norm(axis) < EPSILON)
		axis = v3d_up();
	normal = sqrt(1.0 / (pow(cos(angle * 0.5), 2.0) + pow(axis.x \
			* sin(angle * 0.5), 2.0) + pow(axis.y * sin(angle * 0.5), 2.0) \
			+ pow(axis.z * sin(angle * 0.5), 2.0)));
	from_quat = quat_to_matrix(cos(angle * 0.5) * normal,
			axis.x * sin(angle * 0.5) * normal,
			axis.y * sin(angle * 0.5) * normal,
			axis.z * sin(angle * 0.5) * normal);
	return (m4_mul_rbx(from_quat, position));
}

t_mat4
	m4_lookat(t_vec3d position, t_vec3d target)
{
	t_vec3d unit;

	unit = v3d_unit(v3d_minusv3d(position, target));
	if (unit.x == 0.0 && unit.z == 0.0 && (unit.y == 1.0 || unit.y == -1.0))
		return (lookat_by_quat(position, target));
	else
		return (lookat_by_matrix(position, target));
}
