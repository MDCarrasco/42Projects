/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:36:00 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:19:24 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <object.h>

t_bool
	pln_ray_intersect(t_renderable *self, const t_ray *ray, double *out)
{
	t_plane	plane;
	double	denominator;
	double	t;

	plane = self->var.plane;
	denominator = v3d_dot(plane.rotation, ray->direction);
	if (denominator > EPSILON)
	{
		t = v3d_dot(v3d_minusv3d(plane.center, ray->origin), plane.rotation)
			/ denominator;
		if (t >= 0.0)
		{
			*out = t;
			return (true);
		}
	}
	return (false);
}

t_vec3d
	pln_normal(t_renderable *self, t_vec3d *hit)
{
	(void)hit;
	return (v3d_inverted(self->var.plane.rotation));
}
