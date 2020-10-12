/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 16:25:57 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:29:14 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H
# include <libft.h>
# include <object.h>

typedef struct		s_scene
{
	unsigned char	set;
	t_ull			resolution[2];
	t_color			ambient_color;
	double			ambient_brightness;
	t_vector		objects;
	t_vector		lights;
	t_vector		cameras;
	t_ull			current_camera;
	t_vector		framebuffer;
	t_ull			scale;
}					t_scene;

t_ray				screen_ray(t_scene *scene, t_ull x, t_ull y);
void				scene_render(t_scene *self);
t_bool				scene_cast_ray(t_scene *self, const t_ray *ray,
					t_renderable **hit, double *distance);
#endif
