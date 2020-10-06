/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_destroy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:46:42 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 11:32:41 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <rendering.h>

void	renderer_destroy(t_rendering_obj *renderer)
{
	if (!renderer->window_gone && renderer->win)
		mlx_destroy_window(renderer->mlx, renderer->win);
	if (!renderer->window_gone && renderer->canvas1.img)
		mlx_destroy_image(renderer->mlx, renderer->canvas1.img);
	if (!renderer->window_gone && renderer->canvas2.img)
		mlx_destroy_image(renderer->mlx, renderer->canvas2.img);
	if (renderer->mlx)
		free(renderer->mlx);
	ft_vector_destroy(&renderer->scene->objects);
	ft_vector_destroy(&renderer->scene->lights);
	ft_vector_destroy(&renderer->scene->cameras);
	ft_vector_destroy(&renderer->scene->framebuffer);
}
