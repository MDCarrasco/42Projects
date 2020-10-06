/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_addx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:49 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:26:52 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_rot_addx(t_rendering_obj *renderer)
{
	change_obj_rot(renderer, v3d_fullcon(ROT_DEGREES, 0, 0));
}
