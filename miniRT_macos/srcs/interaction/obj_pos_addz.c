/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_addz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:21:20 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:25:56 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_pos_addz(t_rendering_obj *renderer)
{
	change_obj_pos(renderer, v3d_fullcon(0, 0, TRANSLATE_STEP));
}
