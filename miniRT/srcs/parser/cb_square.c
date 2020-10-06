/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:57:29 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 15:48:47 by micarras         ###   ########.fr       */
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
	add_squares(t_renderable *self, t_square *front, t_scene *s)
{
	t_square	back;
	t_vec3d		normal;

	front->size /= 2.0;
	self->tag = Square;
	self->var.square = *front;
	self->ray_intersect = squ_ray_intersect;
	self->normal = squ_normal;
	self->var.square.other = s->objects.size + 1;
	if (!ft_vector_push(&s->objects, self))
		return (false);
	normal = v3d_timesdouble(front->rotation, 2.0 * EPSILON);
	back = *front;
	back.center = v3d_minusv3d(front->center, normal);
	back.rotation = v3d_inverted(front->rotation);
	back.other = s->objects.size - 1;
	self->var.square = back;
	if (!ft_vector_push(&s->objects, self))
		return (false);
	return (true);
}

t_bool
	cb_square(char **input, t_scene *scene)
{
	t_bool			result;
	t_square		square;
	t_renderable	obj;

	result = (expects(input, "sq")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &square.center)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &square.rotation)
			&& is_normal(square.rotation)
			&& skip_atleast(input, ' ', 1)
			&& take_double(input, &square.size) && square.size > 0.0
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result && !add_squares(&obj, &square, scene))
		return (false);
	return (result);
}
