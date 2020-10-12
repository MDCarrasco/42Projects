/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:21:02 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:21:17 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <math.h>
#include <object.h>
#include <libft.h>

t_bool
	realtri_ray_intersect(t_triangle *self, const t_ray *ray, double *out)
{
	t_vec3d	v0v12[2];
	t_vec3d	ptqvec[3];
	double	uvt[3];
	double	det;

	v0v12[0] = v3d_minusv3d(self->v1, self->v0);
	v0v12[1] = v3d_minusv3d(self->v2, self->v0);
	ptqvec[0] = v3d_cross(ray->direction, v0v12[1]);
	det = v3d_dot(v0v12[0], ptqvec[0]);
	if (fabs(det) < EPSILON)
		return (false);
	ptqvec[1] = v3d_minusv3d(ray->origin, self->v0);
	uvt[0] = v3d_dot(ptqvec[1], ptqvec[0]) / det;
	if (uvt[0] < 0.0 || uvt[0] > 1.0)
		return (false);
	ptqvec[2] = v3d_cross(ptqvec[1], v0v12[0]);
	uvt[1] = v3d_dot(ray->direction, ptqvec[2]) / det;
	if (uvt[1] < 0.0 || uvt[0] + uvt[1] > 1.0)
		return (false);
	uvt[2] = v3d_dot(v0v12[1], ptqvec[2]) / det;
	if (uvt[2] <= 0.0)
		return (false);
	*out = uvt[2];
	return (true);
}

t_bool
	tri_ray_intersect(t_renderable *self, const t_ray *ray, double *out)
{
	t_triangle	*front;

	front = &self->var.triangle;
	return (realtri_ray_intersect(front, ray, out));
}

t_vec3d
	tri_normal(t_renderable *self, t_vec3d *hit)
{
	t_triangle	*triangle;
	t_vec3d		va;
	t_vec3d		vb;
	t_vec3d		result;

	(void)hit;
	triangle = &self->var.triangle;
	if (!triangle->direction)
	{
		va = v3d_minusv3d(triangle->v1, triangle->v0);
		vb = v3d_minusv3d(triangle->v2, triangle->v0);
	}
	else
	{
		va = v3d_minusv3d(triangle->v1, triangle->v2);
		vb = v3d_minusv3d(triangle->v0, triangle->v2);
	}
	result = v3d_unit(v3d_cross(va, vb));
	return (result);
}
