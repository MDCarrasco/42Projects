/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:54:17 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:46:39 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <scene.h>
# include <libft.h>

# define MAX_RES_X 5120
# define MAX_RES_Y 2880

# define RES_SET 1
# define AMB_SET 2
# define ALL_SET 3

t_scene	parse_from_file(const char *path, t_ull scr_x, t_ull scr_y);
t_bool	cb_scene(char **input, t_scene *out, t_ull scr_x, t_ull scr_y);
t_bool	expects(char **input, const char *expected);
t_bool	expectc(char **input, char expected);
t_bool	skip_atleast(char **input, char matcher, t_ull times);
t_bool	cb_resolution(char **input, t_scene *scene);
t_bool	take_number(char **input, t_ull *out);
t_bool	cb_color(char **input, t_color *color);
t_bool	cb_ambient(char **input, t_scene *scene);
t_bool	cb_camera(char **input, t_scene *scene);
t_bool	take_double(char **input, double *out);
t_bool	cb_vector(char **input, t_vec3d *vec);
t_bool	cb_light(char **input, t_scene *scene);
t_bool	cb_sphere(char **input, t_scene *scene);
t_bool	cb_plane(char **input, t_scene *scene);
t_bool	cb_cylinder(char **input, t_scene *scene);
t_bool	cb_triangle(char **input, t_scene *scene);
t_bool	cb_square(char **input, t_scene *scene);

#endif
