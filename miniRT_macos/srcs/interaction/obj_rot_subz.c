/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rot_subz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:24:52 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:28:01 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_rot_subz(t_rendering_obj *renderer)
{
	if (renderer->selection != NULL && renderer->selection->tag == Square)
		return ;
	change_obj_rot(renderer, v3d_fullcon(0, 0, -ROT_DEGREES));
}
