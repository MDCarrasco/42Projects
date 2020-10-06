/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:48:49 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:34:24 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H
# include <stdlib.h>
# include <math.h>
# include <color.h>
# include <libft.h>
# include <ft_mat4.h>

typedef struct			s_ray
{
	t_vec3d				origin;
	t_vec3d				direction;
}						t_ray;

typedef struct			s_sphere
{
	t_vec3d				center;
	double				radius;
}						t_sphere;

typedef struct			s_plane
{
	t_vec3d				center;
	t_vec3d				rotation;
}						t_plane;

typedef struct			s_square
{
	t_vec3d				center;
	t_vec3d				rotation;
	double				size;
	t_ull				other;
}						t_square;

typedef struct			s_triangle
{
	t_vec3d				v0;
	t_vec3d				v1;
	t_vec3d				v2;
	t_ull				other;
	t_bool				direction;
}						t_triangle;

typedef struct			s_cylinder
{
	t_vec3d				center;
	t_vec3d				rotation;
	double				radius;
	double				height;
	t_ull				other;
	t_bool				direction;
}						t_cylinder;

typedef struct			s_light
{
	t_color				color;
	t_vec3d				position;
	double				intensity;
}						t_light;

typedef struct			s_camera
{
	t_mat4				cframe;
	t_vec3d				adjust;
	double				fov;
}						t_camera;

typedef enum			e_render_tag
{
	Sphere,
	Plane,
	Triangle,
	Square,
	Cylinder
}						t_render_tag;

typedef union			u_render_variant
{
	t_sphere			sphere;
	t_plane				plane;
	t_triangle			triangle;
	t_square			square;
	t_cylinder			cylinder;
}						t_render_variant;

typedef struct			s_renderable
{
	t_render_variant	var;
	t_render_tag		tag;
	t_color				color;
	t_bool				(*ray_intersect)(
						struct s_renderable *, const t_ray *, double *out);
	t_vec3d				(*normal)(
						struct s_renderable *, t_vec3d *);
}						t_renderable;

t_ray					ray_fullcon(t_vec3d origin, t_vec3d direction);
t_bool					sph_ray_intersect(t_renderable *self, const t_ray *ray,
						double *out);
t_vec3d					sph_normal(t_renderable *self, t_vec3d *hit);
t_bool					pln_ray_intersect(t_renderable *self, const t_ray *ray,
						double *out);
t_vec3d					pln_normal(t_renderable *self, t_vec3d *hit);
t_bool					cyl_ray_intersect(t_renderable *self, const t_ray *ray,
						double *out);
t_vec3d					cyl_normal(t_renderable *self, t_vec3d *hit);
t_bool					squ_ray_intersect(t_renderable *self, const t_ray *ray,
						double *out);
t_vec3d					squ_normal(t_renderable *self, t_vec3d *hit);
t_bool					tri_ray_intersect(t_renderable *self, const t_ray *ray,
						double *out);
t_bool					realtri_ray_intersect(t_triangle *self,
						const t_ray *ray, double *out);
t_vec3d					tri_normal(t_renderable *self, t_vec3d *hit);
t_light					*lgh_fullcon(const t_vec3d *p, const double i);
void					lgh_destructor(t_light *l);

#endif
