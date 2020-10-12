/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prev_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:26:26 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 18:10:30 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	prev_camera(t_rendering_obj *renderer)
{
	renderer->scene->current_camera =
			(renderer->scene->current_camera - 1) % \
			renderer->scene->cameras.size;
	renderer->last_action = "Switched to previous camera";
}
