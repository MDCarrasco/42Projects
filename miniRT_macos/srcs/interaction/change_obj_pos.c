/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:04:46 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:22:01 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

static void
	relocate_triangle(t_triangle *tri, t_rendering_obj *rdr, t_vec3d offset)
{
	t_triangle	*bck;

	ft_vector_getr(&rdr->scene->objects, tri->other, (void **)&bck);
	tri->v0 = v3d_plusv3d(tri->v0, offset);
	tri->v1 = v3d_plusv3d(tri->v1, offset);
	tri->v2 = v3d_plusv3d(tri->v2, offset);
	bck->v0 = v3d_plusv3d(bck->v0, offset);
	bck->v1 = v3d_plusv3d(bck->v1, offset);
	bck->v2 = v3d_plusv3d(bck->v2, offset);
}

void
	change_obj_pos(t_rendering_obj *renderer, t_vec3d offset)
{
	t_render_variant	*var;
	t_renderable		*ovr;

	if (renderer->selection == NULL)
		return ;
	var = &renderer->selection->var;
	if (renderer->selection->tag == Sphere || renderer->selection->tag == Plane)
		var->sphere.center = v3d_plusv3d(var->sphere.center, offset);
	else if (renderer->selection->tag == Triangle)
		relocate_triangle(&var->triangle, renderer, offset);
	else if (renderer->selection->tag == Square)
	{
		var->square.center = v3d_plusv3d(var->square.center, offset);
		ft_vector_getr(
				&renderer->scene->objects, var->square.other, (void**)&ovr);
		ovr->var.square.center = v3d_plusv3d(ovr->var.square.center, offset);
	}
	else if (renderer->selection->tag == Cylinder)
	{
		var->cylinder.center = v3d_plusv3d(var->cylinder.center, offset);
		ft_vector_getr(
				&renderer->scene->objects, var->cylinder.other, (void**)&ovr);
		ovr->var.cylinder.center =
			v3d_plusv3d(ovr->var.cylinder.center, offset);
	}
}
