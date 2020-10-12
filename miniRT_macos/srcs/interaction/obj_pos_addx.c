/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_addx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:20:25 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:25:32 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_pos_addx(t_rendering_obj *renderer)
{
	change_obj_pos(renderer, v3d_fullcon(TRANSLATE_STEP, 0, 0));
}
