/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down_world.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:16:23 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:23:29 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	move_down_world(t_rendering_obj *renderer)
{
	t_camera	*camera;

	ft_vector_getr(&renderer->scene->cameras,
				renderer->scene->current_camera, (void **)&camera);
	camera->cframe = m4_addv(camera->cframe, v3d_fullcon(0, -CAM_SPEED, 0));
	renderer->last_action = "Moved down on world axis";
}
