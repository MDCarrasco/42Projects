/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_subx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:21:42 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:26:11 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_pos_subx(t_rendering_obj *renderer)
{
	change_obj_pos(renderer, v3d_fullcon(-TRANSLATE_STEP, 0, 0));
}
