/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_subx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:24:01 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:27:36 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_rot_subx(t_rendering_obj *renderer)
{
	change_obj_rot(renderer, v3d_fullcon(-ROT_DEGREES, 0, 0));
}
