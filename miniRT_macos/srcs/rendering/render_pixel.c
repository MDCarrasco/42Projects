/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 20:44:40 by micarras          #+#    #+#             */
/*   Updated: 2020/06/17 10:12:39 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <rendering.h>

t_color
	apply_light(t_scene *scene, t_light light, t_renderable *hit, t_vec3d hitp)
{
	double	dist;
	t_ray	shadow;
	t_vec3d	normal;
	t_vec3d	dir;
	double	intensity;

	normal = hit->normal(hit, &hitp);
	dir = v3d_minusv3d(light.position, hitp);
	shadow = ray_fullcon(v3d_plusv3d(hitp,
				v3d_timesdouble(normal, EPSILON / 2.0)), v3d_unit(dir));
	if (!scene_cast_ray(scene, &shadow, NULL, &dist) \
			|| dist > v3d_magnitude(dir))
	{
		intensity = fmin(light.intensity / (4.0 * M_PI * v3d_norm(dir)) *
				fmax(v3d_dot(normal, dir), 0.0) * LIGHT_MULT, 1.0);
		return (color_mul(hit->color, light.color, intensity));
	}
	return (color_fullcon(0, 0, 0));
}

t_color
	apply_lightning(t_scene *scene, t_renderable *hit, t_vec3d hitp)
{
	t_ull	i;
	t_light	light;
	t_color	cmcol;

	i = 0;
	cmcol = color_fullcon(0, 0, 0);
	while (i < scene->lights.size)
	{
		(void)ft_vector_get(&scene->lights, i, &light);
		cmcol = color_add(cmcol, apply_light(scene, light, hit, hitp));
		i += 1;
	}
	return (cmcol);
}

t_color
	get_pixel(t_scene *scene, t_ull resolution[2], t_ull x, t_ull y)
{
	t_renderable	*hit;
	double			distance;
	t_color			cmcol;
	t_ray			ray;

	ray = screen_ray_res(scene, resolution, x, y);
	cmcol = color_fullcon(0, 0, 0);
	if (scene_cast_ray(scene, &ray, &hit, &distance))
	{
		cmcol = color_add(cmcol, color_mul(hit->color, scene->ambient_color,
					scene->ambient_brightness));
		cmcol = color_add(cmcol, apply_lightning(scene, hit,
					v3d_plusv3d(ray.origin, v3d_timesdouble(ray.direction,
							distance))));
	}
	return (cmcol);
}

t_color
	cap_sized_color(t_ull scale, t_ull col[3])
{
	col[0] /= scale * scale;
	col[1] /= scale * scale;
	col[2] /= scale * scale;
	col[0] = col[0] > 255 ? 255 : col[0];
	col[1] = col[1] > 255 ? 255 : col[1];
	col[2] = col[2] > 255 ? 255 : col[2];
	return (color_fullcon(col[0], col[1], col[2]));
}

void
	render_pixel(t_scene *s, t_ull x, t_ull y)
{
	t_ull	scaled[2];
	t_ull	evt_col[3];
	t_ull	res[2];
	t_color tmp;

	res[0] = s->resolution[0] * s->scale;
	res[1] = s->resolution[1] * s->scale;
	ft_bzero(evt_col, 3 * sizeof(t_ull));
	ft_bzero(scaled, 2 * sizeof(t_ull));
	while (scaled[0] < s->scale)
	{
		scaled[1] = 0;
		while (scaled[1] < s->scale)
		{
			tmp = get_pixel(s, res, x * s->scale + scaled[1],
					y * s->scale + scaled[1]);
			evt_col[0] += tmp.r;
			evt_col[1] += tmp.g;
			evt_col[2] += tmp.b;
			scaled[1] += 1;
		}
		scaled[0] += 1;
	}
	tmp = cap_sized_color(s->scale, evt_col);
	(void)ft_vector_set(&s->framebuffer, y * s->resolution[0] + x, &tmp);
}
