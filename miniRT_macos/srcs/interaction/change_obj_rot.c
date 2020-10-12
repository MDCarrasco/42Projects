/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:09:01 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:56:01 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <interaction.h>

static t_vec3d
	rotate(t_vec3d rotation, t_vec3d *offset)
{
	t_mat4	rotator;

	rotator = m4_lookat(v3d_defaultcon(), rotation);
	rotator = m4_mul(rotator, m4_angles(
			rad(offset->x), rad(offset->y), rad(offset->z)));
	return (m4_look_vec(rotator));
}

void
	change_obj_rot(t_rendering_obj *renderer, t_vec3d offset)
{
	t_render_variant	*var;
	t_renderable		*ovr;

	if (renderer->selection == NULL)
		return ;
	var = &renderer->selection->var;
	if (renderer->selection->tag == Plane)
		var->plane.rotation = rotate(var->plane.rotation, &offset);
	else if (renderer->selection->tag == Square)
	{
		var->square.rotation = rotate(var->square.rotation, &offset);
		ft_vector_getr(
				&renderer->scene->objects, var->square.other, (void**)&ovr);
		ovr->var.square.rotation = v3d_inverted(var->square.rotation);
		ovr->var.square.center = v3d_minusv3d(var->square.center,
				v3d_timesdouble(var->square.rotation, 2.0 * EPSILON));
	}
	else if (renderer->selection->tag == Cylinder)
	{
		var->cylinder.rotation = rotate(var->cylinder.rotation, &offset);
		ft_vector_getr(
				&renderer->scene->objects, var->cylinder.other, (void**)&ovr);
		ovr->var.cylinder.rotation = var->cylinder.rotation;
	}
}
