/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 21:11:30 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:04:44 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <math.h>
#include <minirt.h>

t_ray
	screen_ray(t_scene *scene, t_ull x, t_ull y)
{
	double		scale;
	double		ratio;
	t_camera	camera;
	t_vec3d		dir;

	ft_vector_get(&scene->cameras, scene->current_camera, &camera);
	camera.cframe = m4_mul(m4_angles(
				fmod(camera.adjust.x, M_PI * 2),
				fmod(camera.adjust.y, M_PI * 2),
				fmod(camera.adjust.z, M_PI * 2)), camera.cframe);
	scale = tan(rad(camera.fov * 0.5));
	ratio = (double)scene->resolution[0] / (double)scene->resolution[1];
	dir = v3d_fullcon((2.0 * (x + 0.5) / (double)scene->resolution[0] - 1.0)
			* ratio * scale, (1.0 - 2.0 * (y + 0.5) /
				(double)scene->resolution[1]) * scale, -1.0);
	dir = v3d_unit(m4_mulv_dir(camera.cframe, dir));
	return (ray_fullcon(m4_pos(camera.cframe), dir));
}

t_ray
	screen_ray_res(t_scene *scene, const t_ull resolution[2], t_ull x, t_ull y)
{
	double		scale;
	double		ratio;
	t_camera	camera;
	t_vec3d		dir;

	ft_vector_get(&scene->cameras, scene->current_camera, &camera);
	camera.cframe = m4_mul(m4_angles(
			fmod(camera.adjust.x, M_PI * 2),
			fmod(camera.adjust.y, M_PI * 2),
			fmod(camera.adjust.z, M_PI * 2)), camera.cframe);
	scale = tan(rad(camera.fov * 0.5));
	ratio = (double)resolution[0] / (double)resolution[1];
	dir = v3d_fullcon((2.0 * (x + 0.5) / (double)resolution[0] - 1.0)
			* ratio * scale, (1.0 - 2.0 * (y + 0.5) /
			(double)resolution[1]) * scale, -1.0);
	dir = v3d_unit(m4_mulv_dir(camera.cframe, dir));
	return (ray_fullcon(m4_pos(camera.cframe), dir));
}
