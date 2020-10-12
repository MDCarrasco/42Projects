/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_renderer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:47:19 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:55:30 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <rendering.h>
#include <parser.h>

void
	setup_canvas(t_rendering_obj *renderer, t_scene *scene)
{
	renderer->current_canvas = 0;
	renderer->canvas1.img = mlx_new_image(renderer->mlx, scene->resolution[0],
										scene->resolution[1]);
	renderer->canvas2.img = mlx_new_image(renderer->mlx, scene->resolution[0],
										scene->resolution[1]);
	if (renderer->canvas1.img)
		renderer->canvas1.data = mlx_get_data_addr(renderer->canvas1.img,
				&renderer->canvas1.bits_per_pixel,
				&renderer->canvas1.size_line, &renderer->canvas1.endian);
	else
	{
		renderer_destroy(renderer);
		panic("failed to create a canvas", false);
	}
	if (renderer->canvas2.img)
		renderer->canvas2.data = mlx_get_data_addr(renderer->canvas2.img,
				&renderer->canvas2.bits_per_pixel,
				&renderer->canvas2.size_line, &renderer->canvas2.endian);
	else
	{
		renderer_destroy(renderer);
		panic("failed to create a canvas", false);
	}
}

void
	setup_renderer(t_rendering_obj *renderer, t_scene *scene)
{
	assert(renderer->mlx != NULL, "unable to initialize context", false);
	renderer->win = mlx_new_window(
			renderer->mlx, scene->resolution[0], scene->resolution[1],
			"minirt");
	if (renderer->win == NULL)
	{
		renderer_destroy(renderer);
		panic("failed to create a window", false);
	}
	setup_canvas(renderer, scene);
	renderer->update_render = 0;
	renderer->update_key = 1;
	renderer->target = v3d_defaultcon();
	renderer->window_gone = false;
	renderer->last_action = IS_BONUS ? "Start (BONUS)" : "Start";
}
