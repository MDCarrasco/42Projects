/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pos_subz.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:22:23 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:26:35 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>

void
	obj_pos_subz(t_rendering_obj *renderer)
{
	change_obj_pos(renderer, v3d_fullcon(0, 0, -TRANSLATE_STEP));
}
