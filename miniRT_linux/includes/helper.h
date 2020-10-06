/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:55:09 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:36:08 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <ft_vec3d.h>
# include <ft_mat4.h>

typedef struct	s_cylinder_helper
{
	t_vec3d	p;
	t_vec3d	v;
	t_vec3d	pa;
	t_vec3d	va;
	t_vec3d	dp;
	t_vec3d	common1;
	t_vec3d	common2;
	double	abc[3];
	t_vec3d	p1;
	t_vec3d	p2;
}				t_cylinder_helper;

typedef struct	s_square_helper
{
	t_mat4		local;
	t_vec3d		upv;
	t_vec3d		rgv;
	t_vec3d		pa;
	t_vec3d		pb;
	t_vec3d		pc;
	t_vec3d		pd;
}				t_square_helper;

#endif
