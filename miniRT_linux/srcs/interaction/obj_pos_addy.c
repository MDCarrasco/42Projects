/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_addy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:20:49 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:25:45 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_pos_addy(t_rendering_obj *renderer)
{
	change_obj_pos(renderer, v3d_fullcon(0, TRANSLATE_STEP, 0));
}
