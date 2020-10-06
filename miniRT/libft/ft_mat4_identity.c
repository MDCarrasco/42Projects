/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_identity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:41:17 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:50:45 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mat4.h>

t_mat4
	m4_identity(void)
{
	t_vec3d	zeroed;

	zeroed = v3d_defaultcon();
	return (m4_fullcon(g_v3d_right, g_v3d_up, g_v3d_forward, zeroed));
}
