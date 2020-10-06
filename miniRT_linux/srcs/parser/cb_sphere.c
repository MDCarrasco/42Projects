/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:53:53 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:47:13 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool
	cb_sphere(char **input, t_scene *scene)
{
	t_bool			result;
	t_sphere		sphere;
	t_renderable	obj;

	result = (expects(input, "sp")
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &sphere.center)
			&& skip_atleast(input, ' ', 1)
			&& take_double(input, &sphere.radius)
			&& (sphere.radius / 2.0) > 0.0
			&& skip_atleast(input, ' ', 1)
			&& cb_color(input, &obj.color));
	if (result)
	{
		sphere.radius /= 2.0;
		obj.var.sphere = sphere;
		obj.tag = Sphere;
		obj.ray_intersect = sph_ray_intersect;
		obj.normal = sph_normal;
	}
	if (result && !ft_vector_push(&scene->objects, &obj))
		return (false);
	return (result);
}
