/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:06:02 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 15:49:10 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool
	add_triangles(t_renderable *self, t_triangle *front, t_scene *s)
{
	t_triangle	back;
	t_vec3d		normal;

	front->other = s->objects.size + 1;
	front->direction = true;
	self->var.triangle = *front;
	self->tag = Triangle;
	self->ray_intersect = tri_ray_intersect;
	self->normal = tri_normal;
	if (!ft_vector_push(&s->objects, self))
		return (false);
	normal = v3d_timesdouble(tri_normal(self, &front->v0), 2.0 * -EPSILON);
	back.direction = false;
	back.other = s->objects.size - 1;
	back.v0 = v3d_plusv3d(front->v0, normal);
	back.v1 = v3d_plusv3d(front->v1, normal);
	back.v2 = v3d_plusv3d(front->v2, normal);
	self->var.triangle = back;
	if (!ft_vector_push(&s->objects, self))
		return (false);
	return (true);
}

t_bool
	cb_triangle(char **input, t_scene *scene)
{
	t_bool			result;
	t_triangle		triangle;
	t_renderable	obj;

	result = (expects(input, "tr")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &triangle.v0)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &triangle.v1)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &triangle.v2)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result && !add_triangles(&obj, &triangle, scene))
		return (false);
	return (result);
}
