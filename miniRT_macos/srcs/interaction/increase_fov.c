/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_fov.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:14:52 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 11:11:43 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	increase_fov(t_rendering_obj *renderer)
{
	t_camera	*camera;

	ft_vector_getr(&renderer->scene->cameras,
				renderer->scene->current_camera, (void **)&camera);
	camera->fov += CAM_FOV_STEP;
	renderer->last_action = "Increased FOV";
}
