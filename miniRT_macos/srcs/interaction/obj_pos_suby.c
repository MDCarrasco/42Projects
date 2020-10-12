/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_suby.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:04 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:26:21 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_pos_suby(t_rendering_obj *renderer)
{
	change_obj_pos(renderer, v3d_fullcon(0, -TRANSLATE_STEP, 0));
}
