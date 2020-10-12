/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:00:39 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:19:09 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <object.h>

t_bool
	sph_ray_intersect(t_renderable *self, const t_ray *ray, double *out)
{
	t_vec3d		line;
	double		tca;
	double		tmp;

	line = v3d_minusv3d(self->var.sphere.center, ray->origin);
	tca = v3d_dot(line, ray->direction);
	if (tca < 0.0)
		return (false);
	tmp = v3d_dot(line, line) - pow(tca, 2.0);
	if (tmp > pow(self->var.sphere.radius, 2.0))
		return (false);
	tmp = sqrt(pow(self->var.sphere.radius, 2.0) - tmp);
	line.x = tca - tmp;
	line.y = tca + tmp;
	if (line.x > line.y)
	{
		tmp = line.x;
		line.x = line.y;
		line.y = tmp;
	}
	if (line.x < 0.0 && line.y < 0.0)
		return (false);
	*out = line.x < 0.0 ? line.y : line.x;
	return (true);
}

t_vec3d
	sph_normal(t_renderable *self, t_vec3d *hit)
{
	return (v3d_unit(v3d_minusv3d(*hit, self->var.sphere.center)));
}
