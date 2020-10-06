/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:44:57 by micarras          #+#    #+#             */
/*   Updated: 2020/06/17 10:29:27 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H
# include <libft.h>
# include <object.h>
# include <color.h>
# include <scene.h>
# include <mlx.h>

typedef	struct			s_canvas
{
	void				*img;
	char				*data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_canvas;

typedef struct			s_rendering_obj
{
	void				*mlx;
	void				*win;
	t_canvas			canvas1;
	t_canvas			canvas2;
	char				current_canvas;
	t_ull				update_key;
	t_ull				update_render;
	t_scene				*scene;
	t_bool				window_gone;
	t_renderable		*selection;
	t_vec3d				target;
	char				*last_action;
}						t_rendering_obj;

typedef struct			s_thread_msg
{
	t_scene				*scene;
	int					id;
}						t_thread_msg;

int						render(t_rendering_obj *renderer);
void					renderer_destroy(t_rendering_obj *renderer);
void					setup_renderer(t_rendering_obj *renderer,
						t_scene *scene);
void					canvas_put_pixel(t_canvas *self, unsigned int x,
						unsigned int y, unsigned int color);
void					render_pixel(t_scene *scene, t_ull x, t_ull y);
t_ray					screen_ray_res(t_scene *scene,
						const t_ull resolution[2], t_ull x, t_ull y);
t_bool					output_bmp(t_vector *colors, unsigned int width,
						unsigned int height);

#endif
