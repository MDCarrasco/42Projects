/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:11:24 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:40:47 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <math.h>

static void
	change_obj_size(t_rendering_obj *renderer, double step)
{
	t_render_variant	*var;
	t_renderable		*ovr;

	if (renderer->selection == NULL)
		return ;
	var = &renderer->selection->var;
	if (renderer->selection->tag == Sphere)
		var->sphere.radius = fmax(.1, var->sphere.radius + step);
	else if (renderer->selection->tag == Square)
	{
		var->square.size = fmax(.1, var->square.size + step);
		ft_vector_getr(
				&renderer->scene->objects, var->square.other, (void**)&ovr);
		ovr->var.square.size = fmax(.1, ovr->var.square.size + step);
	}
	else if (renderer->selection->tag == Cylinder)
	{
		var->cylinder.radius = fmax(.1, var->cylinder.radius + step);
		var->cylinder.height = fmax(.1, var->cylinder.height + step);
		ft_vector_getr(
				&renderer->scene->objects, var->cylinder.other, (void**)&ovr);
		ovr->var.cylinder.radius = fmax(.1, ovr->var.cylinder.radius + step);
		ovr->var.cylinder.height = fmax(.1, ovr->var.cylinder.height + step);
	}
}

void
	increase_obj_size(t_rendering_obj *renderer)
{
	change_obj_size(renderer, RESIZE_STEP);
}

void
	decrease_obj_size(t_rendering_obj *renderer)
{
	change_obj_size(renderer, -RESIZE_STEP);
}
