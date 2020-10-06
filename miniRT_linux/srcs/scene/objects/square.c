/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:01:48 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 15:47:08 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <object.h>
#include <helper.h>

static void
	setup_helper(t_square *sq, t_square_helper *hp)
{
	hp->local = m4_lookat(sq->center, v3d_plusv3d(sq->center, sq->rotation));
	hp->upv = v3d_timesdouble(m4_up_vec(hp->local), sq->size);
	hp->rgv = v3d_timesdouble(m4_right_vec(hp->local), sq->size);
	hp->pa = v3d_plusv3d(v3d_minusv3d(sq->center, hp->upv), hp->rgv);
	hp->pb = v3d_plusv3d(v3d_plusv3d(sq->center, hp->upv), hp->rgv);
	hp->pc = v3d_minusv3d(v3d_plusv3d(sq->center, hp->upv), hp->rgv);
	hp->pd = v3d_minusv3d(v3d_minusv3d(sq->center, hp->upv), hp->rgv);
}

t_bool
	squ_ray_intersect(struct s_renderable *self, const t_ray *ray, double *out)
{
	t_square_helper	helper;
	t_triangle		tri[2];
	double			res[2];
	double			hits[2];

	setup_helper(&self->var.square, &helper);
	tri[0].v0 = helper.pa;
	tri[0].v1 = helper.pb;
	tri[0].v2 = helper.pc;
	tri[1].v0 = helper.pa;
	tri[1].v1 = helper.pd;
	tri[1].v2 = helper.pc;
	hits[0] = realtri_ray_intersect(&tri[0], ray, &res[0]);
	hits[1] = realtri_ray_intersect(&tri[1], ray, &res[1]);
	if (hits[0] && hits[1])
		*out = fmin(res[0], res[1]);
	else if (hits[0])
		*out = res[0];
	else if (hits[1])
		*out = res[1];
	return (hits[0] || hits[1]);
}

t_vec3d
	squ_normal(struct s_renderable *self, t_vec3d *hit)
{
	(void)hit;
	return (self->var.plane.rotation);
}
