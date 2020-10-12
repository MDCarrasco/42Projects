/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:28:42 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:57:28 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <interaction.h>

void
	rotate_right(t_rendering_obj *renderer)
{
	t_camera	*camera;

	ft_vector_getr(&renderer->scene->cameras,
				renderer->scene->current_camera, (void **)&camera);
	camera->adjust = v3d_plusv3d(
			camera->adjust, v3d_fullcon(0, rad(CAM_ROT_SPEED), 0));
	renderer->last_action = "Rotated right";
}
