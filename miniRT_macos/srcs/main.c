/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 17:48:37 by micarras          #+#    #+#             */
/*   Updated: 2020/06/17 11:21:39 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <rendering.h>
#include <parser.h>
#include <minirt.h>
#include <scene.h>
#include <interaction.h>

const t_key_pair g_interactions[] =
{
	{Escape, exit_program},
	{Q, move_down_world},
	{E, move_up_world},
	{W, move_forward},
	{S, move_backward},
	{A, move_left},
	{D, move_right},
	{Left, rotate_left},
	{Right, rotate_right},
	{Up, pitch_up},
	{Down, pitch_down},
	{Plus, increase_fov},
	{Minus, decrease_fov},
	{Comma, roll_left},
	{Dot, roll_right},
	{F1, next_camera},
	{F2, prev_camera},
	{F3, increase_obj_size},
	{F4, decrease_obj_size},
	{F5, scale_up},
	{F6, scale_down},
	{R, obj_pos_suby},
	{Y, obj_pos_addy},
	{T, obj_pos_addz},
	{G, obj_pos_subz},
	{F, obj_pos_subx},
	{H, obj_pos_addx},
	{J, obj_rot_suby},
	{L, obj_rot_addy},
	{U, obj_rot_addz},
	{O, obj_rot_subz},
	{I, obj_rot_subx},
	{K, obj_rot_addx},
	{-1, NULL}
};

int
	key_handle(int keycode, t_rendering_obj *renderer)
{
	t_ull	i;

	i = 0;
	while (g_interactions[i].action != NULL)
	{
		if (g_interactions[i].keycode == keycode)
			g_interactions[i].action(renderer);
		i += 1;
	}
	renderer->update_key += 1;
	return (0);
}

int
	mouse_handle(int button, int x, int y, t_rendering_obj *renderer)
{
	t_ray			ray;
	double			distance;
	t_camera		*cur;
	t_scene			*scene;
	t_renderable	*select;

	scene = renderer->scene;
	ft_vector_getr(&scene->cameras, scene->current_camera, (void **)&cur);
	ray = screen_ray(scene, x, y);
	select = NULL;
	if (button != 3 && button != 1)
		return (false);
	if (scene_cast_ray(scene, &ray, &select, &distance))
	{
		cur->adjust = button == 3 ? v3d_defaultcon() : cur->adjust;
		if (button == 3)
			cur->cframe = m4_lookat(m4_pos(cur->cframe), \
					v3d_plusv3d(ray.origin,
						v3d_timesdouble(ray.direction, distance)));
	}
	renderer->selection = button == 1 ? select : renderer->selection;
	renderer->last_action = button == 3 ? "Looking at" : "Selected object";
	renderer->update_key += 1;
	return (0);
}

void
	start_mlx(t_rendering_obj *renderer)
{
	mlx_loop_hook(renderer->mlx, render, renderer);
	mlx_mouse_hook(renderer->win, mouse_handle, renderer);
	mlx_key_hook(renderer->win, key_handle, renderer);
	mlx_hook(renderer->win, 17, (1L << 17), exit_program_i, renderer);
	mlx_loop(renderer->mlx);
}

void
	main_bis(char **argv, t_rendering_obj *renderer, t_scene *scene)
{
	int	scr_x;
	int	scr_y;

	ft_bzero(renderer, sizeof(renderer));
	ft_bzero(scene, sizeof(scene));
	renderer->mlx = mlx_init();
	mlx_get_screen_size(renderer->mlx, &scr_x, &scr_y);
	*scene = parse_from_file(argv[1], scr_x, scr_y);
	renderer->scene = scene;
}

int
	main(int argc, char **argv)
{
	t_scene			scene;
	t_rendering_obj	renderer;

	if (argc < 2)
		panic("no file has been provided", false);
	if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 3]), ".rt", 4) != 0)
		panic("the provided file has an invalid extension", false);
	main_bis(argv, &renderer, &scene);
	if (argc >= 3 && ft_strncmp(argv[2], "-save", 5) == 0)
	{
		scene_render(&scene);
		if (!output_bmp(&scene.framebuffer, (unsigned int)scene.resolution[0],
					(unsigned int)scene.resolution[1]))
		{
			renderer_destroy(&renderer);
			panic("failed to output bmp", false);
		}
		renderer_destroy(&renderer);
		return (0);
	}
	setup_renderer(&renderer, &scene);
	start_mlx(&renderer);
	return (0);
}
