/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roll_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:26:42 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:56:43 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <interaction.h>

void
	roll_left(t_rendering_obj *renderer)
{
	t_camera	*camera;

	ft_vector_getr(&renderer->scene->cameras,
				renderer->scene->current_camera, (void **)&camera);
	camera->adjust = v3d_minusv3d(
			camera->adjust, v3d_fullcon(0, 0, rad(CAM_ROT_SPEED)));
	renderer->last_action = "Rolled left";
}
