/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_addz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:23:34 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:27:25 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_rot_addz(t_rendering_obj *renderer)
{
	if (renderer->selection != NULL && renderer->selection->tag == Square)
		return ;
	change_obj_rot(renderer, v3d_fullcon(0, 0, ROT_DEGREES));
}
