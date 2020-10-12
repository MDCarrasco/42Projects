/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:20:48 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:31:23 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool
	is_normal(t_vec3d v)
{
	double	magnitude;

	magnitude = v3d_magnitude(v);
	return (magnitude > (1 - EPSILON) && magnitude < (1 + EPSILON));
}

t_bool
	add_cylinders(t_renderable *self, t_cylinder *outer, t_scene *s)
{
	t_cylinder		inner;

	self->var.cylinder.other = s->objects.size + 1;
	if (!ft_vector_push(&s->objects, self))
		return (false);
	inner = *outer;
	inner.direction = false;
	inner.radius -= EPSILON * 2.0;
	inner.other = s->objects.size - 1;
	self->var.cylinder = inner;
	if (!ft_vector_push(&s->objects, self))
		return (false);
	return (true);
}

static void
	init_obj(t_renderable *obj, t_cylinder *cylinder)
{
	cylinder->radius /= 2.0;
	cylinder->direction = true;
	obj->tag = Cylinder;
	obj->var.cylinder = *cylinder;
	obj->ray_intersect = cyl_ray_intersect;
	obj->normal = cyl_normal;
}

t_bool
	cb_cylinder(char **input, t_scene *scene)
{
	t_bool			result;
	t_cylinder		cylinder;
	t_renderable	obj;

	result = (expects(input, "cy")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &cylinder.center)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &cylinder.rotation)
			&& is_normal(cylinder.rotation)
			&& skip_atleast(input, ' ', 1)
			&& take_double(input, &cylinder.radius) && cylinder.radius > 0.0
			&& skip_atleast(input, ' ', 1)
			&& take_double(input, &cylinder.height) && cylinder.height > 0.0
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result)
		init_obj(&obj, &cylinder);
	if (result && !add_cylinders(&obj, &cylinder, scene))
		return (false);
	return (result);
}
