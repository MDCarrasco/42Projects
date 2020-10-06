/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_camera.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:14:14 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:31:03 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_bool
	cb_camera(char **input, t_scene *scene)
{
	t_bool		result;
	t_camera	camera;
	t_vec3d		from;
	t_vec3d		to;

	ft_bzero((void *)&camera, sizeof(t_camera));
	result = (expectc(input, 'c')
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &from)
			&& skip_atleast(input, ' ', 1)
			&& cb_vector(input, &to)
			&& skip_atleast(input, ' ', 1)
			&& take_double(input, &camera.fov));
	if (result)
		camera.cframe = m4_lookat(from, v3d_plusv3d(from, to));
	if (result && ft_vector_push(&scene->cameras, &camera))
		return (true);
	return (result);
}
