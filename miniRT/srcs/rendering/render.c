/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 13:54:25 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 17:05:12 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scene.h>
#include <minirt.h>
#include <rendering.h>

#if IS_BONUS == 1
# include <pthread.h>
#endif

int
	render(t_rendering_obj *renderer)
{
	t_ull		pixel;
	t_color		color;
	t_canvas	canvas;

	if (renderer->update_render < renderer->update_key)
	{
		pixel = 0;
		canvas = renderer->current_canvas ?
			renderer->canvas1 : renderer->canvas2;
		scene_render(renderer->scene);
		while (pixel < renderer->scene->framebuffer.size)
		{
			ft_vector_get(&renderer->scene->framebuffer, pixel, &color);
			canvas_put_pixel(&canvas, pixel % renderer->scene->resolution[0],
					pixel / (renderer->scene->resolution[0]),
					color_as_uint(color));
			pixel += 1;
		}
		renderer->current_canvas = (char)!renderer->current_canvas;
		mlx_put_image_to_window(renderer->mlx, renderer->win, canvas.img, 0, 0);
		mlx_string_put(renderer->mlx, renderer->win, 0, 10, 0x00FFFFFF,
				renderer->last_action);
		renderer->update_render += 1;
	}
	return (0);
}

void
	*worker(void *msg_arg)
{
	t_thread_msg	*message;
	t_ull			x;
	t_ull			y;

	message = msg_arg;
	x = 0;
	y = message->id;
	while (y < message->scene->resolution[1])
	{
		x = 0;
		while (x < message->scene->resolution[0])
		{
			render_pixel(message->scene, x, y);
			x += 1;
		}
		y += THREAD_COUNT;
	}
	return (NULL);
}

#if IS_BONUS == 1

void
	scene_render(t_scene *scene)
{
	t_ull			x;
	pthread_t		threads[THREAD_COUNT];
	t_thread_msg	messages[THREAD_COUNT];

	scene->framebuffer.size = scene->framebuffer.capacity;
	x = 0;
	while (x < THREAD_COUNT)
	{
		messages[x].scene = scene;
		messages[x].id = x;
		if (pthread_create(&threads[x], NULL, worker, &messages[x]) != 0)
		{
			worker(&messages[x]);
			messages[x].scene = NULL;
		}
		x += 1;
	}
	while (x > 0)
	{
		x -= 1;
		if (messages[x].scene != NULL)
			pthread_join(threads[x], NULL);
	}
	return ;
}

#else

void
	scene_render(t_scene *scene)
{
	t_thread_msg	message;

	scene->framebuffer.size = scene->framebuffer.capacity;
	message.scene = scene;
	message.id = 0;
	worker(&message);
}

#endif
