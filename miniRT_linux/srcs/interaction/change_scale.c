/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:12:54 by micarras          #+#    #+#             */
/*   Updated: 2020/06/11 18:00:16 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	scale_up(t_rendering_obj *renderer)
{
	renderer->scene->scale += 1;
	renderer->last_action = "Increased SSAA";
	if (renderer->scene->scale == 2)
		renderer->last_action = "Enabled SSAA";
}

void
	scale_down(t_rendering_obj *renderer)
{
	renderer->scene->scale -= 1;
	renderer->last_action = "Decreased SSAA";
	if (renderer->scene->scale < 2)
	{
		renderer->scene->scale = 1;
		renderer->last_action = "Disabled SSAA";
	}
}
