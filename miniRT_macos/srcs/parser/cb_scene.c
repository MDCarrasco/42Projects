/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:44:09 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:09:45 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_bool
	scene_init(t_scene *scene)
{
	t_bool	res;

	res = ft_vector_new(&scene->lights, sizeof(t_light));
	res = ft_vector_new(&scene->cameras, sizeof(t_camera)) && res;
	res = ft_vector_new(&scene->objects, sizeof(t_renderable)) && res;
	scene->scale = 1;
	scene->current_camera = 0;
	if (!res)
	{
		ft_vector_destroy(&scene->lights);
		ft_vector_destroy(&scene->cameras);
		ft_vector_destroy(&scene->objects);
	}
	return (res);
}

static t_bool
	cb_scene_normal(char **input, t_scene *out)
{
	t_bool	fr;

	if (!scene_init(out))
		return (false);
	fr = false;
	out->set = 0;
	skip_atleast(input, '\n', 0);
	while (1)
	{
		if (fr && !skip_atleast(input, '\n', 1))
			break ;
		if (!(cb_resolution(input, out) || cb_ambient(input, out) \
			|| cb_cylinder(input, out) || cb_light(input, out) \
			|| cb_sphere(input, out) || cb_plane(input, out) \
			|| cb_camera(input, out) || cb_triangle(input, out) \
			|| cb_square(input, out)))
			break ;
		fr = true;
	}
	skip_atleast(input, '\n', 0);
	return (out->set == ALL_SET && out->cameras.size != 0);
}

t_bool
	cb_scene(char **input, t_scene *out, t_ull scr_x, t_ull scr_y)
{
	t_bool	result;

	result = cb_scene_normal(input, out);
	if (out->resolution[0] > scr_x)
		out->resolution[0] = scr_x;
	if (out->resolution[1] > scr_y)
		out->resolution[1] = scr_y;
	if (result)
		if (!ft_vector_with_capacity(&out->framebuffer, sizeof(t_color),
					out->resolution[0] * out->resolution[1]))
		{
			ft_vector_destroy(&out->lights);
			ft_vector_destroy(&out->cameras);
			ft_vector_destroy(&out->objects);
			return (false);
		}
	return (result);
}
