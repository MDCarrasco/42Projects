/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:35:10 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:09:18 by micarras         ###   ########.fr       */
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
	cb_plane(char **input, t_scene *scene)
{
	t_bool			result;
	t_plane			plane;
	t_renderable	obj;

	result = (expects(input, "pl")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &plane.center)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &plane.rotation)
			&& is_normal(plane.rotation)
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result)
	{
		plane.rotation = v3d_inverted(plane.rotation);
		obj.var.plane = plane;
		obj.tag = Plane;
		obj.ray_intersect = pln_ray_intersect;
		obj.normal = pln_normal;
	}
	return (result && ft_vector_push(&scene->objects, &obj));
}
