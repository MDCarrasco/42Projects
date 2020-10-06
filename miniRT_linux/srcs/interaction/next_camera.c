/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:20:05 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 18:09:53 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	next_camera(t_rendering_obj *renderer)
{
	renderer->scene->current_camera =
			(renderer->scene->current_camera + 1) % \
			renderer->scene->cameras.size;
	renderer->last_action = "Switched to next camera";
}
