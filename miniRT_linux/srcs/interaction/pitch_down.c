/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pitch_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:25:17 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:56:28 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <interaction.h>

void
	pitch_down(t_rendering_obj *renderer)
{
	t_camera	*camera;

	ft_vector_getr(&renderer->scene->cameras,
				renderer->scene->current_camera, (void **)&camera);
	camera->adjust = v3d_plusv3d(
			camera->adjust, v3d_fullcon(rad(CAM_ROT_SPEED), 0, 0));
	renderer->last_action = "Pitched down";
}
