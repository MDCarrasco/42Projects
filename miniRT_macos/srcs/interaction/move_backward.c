/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:17:23 by micarras          #+#    #+#             */
/*   Updated: 2020/06/17 10:44:58 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <math.h>

void
	move_backward(t_rendering_obj *renderer)
{
	t_mat4		rel;
	t_camera	*camera;

	ft_vector_getr(&renderer->scene->cameras,
				renderer->scene->current_camera, (void **)&camera);
	rel = m4_mul(m4_angles(fmod(camera->adjust.x, M_PI * 2),
			fmod(camera->adjust.y, M_PI * 2),
			fmod(camera->adjust.z, M_PI * 2)), camera->cframe);
	camera->cframe = m4_addv(camera->cframe, m4_look_vec(rel));
	renderer->last_action = "Moved backward";
}
