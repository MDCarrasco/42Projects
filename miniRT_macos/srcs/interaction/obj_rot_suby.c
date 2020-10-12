/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_suby.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:24:29 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:27:49 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_rot_suby(t_rendering_obj *renderer)
{
	change_obj_rot(renderer, v3d_fullcon(0, -ROT_DEGREES, 0));
}
