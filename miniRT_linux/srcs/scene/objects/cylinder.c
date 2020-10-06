/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 19:42:30 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:55:46 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <helper.h>
#include <object.h>

static t_cylinder_helper
	calc_vars(t_cylinder *cyl, const t_ray *ray)
{
	t_cylinder_helper	vars;

	vars.p = ray->origin;
	vars.v = ray->direction;
	vars.pa = cyl->center;
	vars.va = cyl->rotation;
	vars.dp = v3d_minusv3d(vars.p, vars.pa);
	vars.common1 = v3d_minusv3d(vars.v, v3d_timesdouble(vars.va,
				v3d_dot(vars.v, vars.va)));
	vars.common2 = v3d_minusv3d(vars.dp, v3d_timesdouble(vars.va,
				v3d_dot(vars.dp, vars.va)));
	vars.abc[0] = v3d_norm(vars.common1);
	vars.abc[1] = 2.0 * v3d_dot(vars.common1, vars.common2);
	vars.abc[2] = v3d_norm(vars.common2) - pow(cyl->radius, 2);
	vars.p1 = v3d_minusv3d(vars.pa, v3d_timesdouble(vars.va,
	cyl->height / 2.0));
	vars.p2 = v3d_plusv3d(vars.pa, v3d_timesdouble(vars.va, cyl->height / 2.0));
	return (vars);
}

static t_bool
	real_intersect(t_cylinder *self, const t_ray *ray, double *out)
{
	t_cylinder_helper	helper;
	double				t[3];
	t_vec3d				q;
	double				res;

	helper = calc_vars(self, ray);
	res = -1;
	if (solve_quad(helper.abc, t))
	{
		q = v3d_plusv3d(helper.p, v3d_timesdouble(helper.v, t[0]));
		if (t[0] > 0.0 && v3d_dot(helper.va, v3d_minusv3d(q, helper.p1)) > 0.0 \
			&& v3d_dot(helper.va, v3d_minusv3d(q, helper.p2)) < 0.0)
			res = t[0];
		q = v3d_plusv3d(helper.p, v3d_timesdouble(helper.v, t[1]));
		if (t[1] > 0.0 && v3d_dot(helper.va, v3d_minusv3d(q, helper.p1)) > 0.0 \
			&& v3d_dot(helper.va, v3d_minusv3d(q, helper.p2)) < 0.0)
			res = res != -1 ? fmin(t[0], t[1]) : t[1];
	}
	if (res != -1)
		*out = res;
	return (res != -1);
}

t_bool
	cyl_ray_intersect(t_renderable *self, const t_ray *ray, double *out)
{
	t_cylinder	*outer;

	outer = &self->var.cylinder;
	return (real_intersect(outer, ray, out));
}

t_vec3d
	cyl_normal(t_renderable *self, t_vec3d *hit)
{
	t_cylinder *cyl;

	cyl = &self->var.cylinder;
	if (cyl->direction)
		return (v3d_unit(v3d_minusv3d(*hit, cyl->center)));
	else
		return (v3d_inverted(v3d_unit(v3d_minusv3d(*hit, cyl->center))));
}
