/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat4_right_vec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:08:32 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:53:22 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_mat4.h>

t_vec3d
	m4_right_vec(t_mat4 m)
{
	return (v3d_unit(v3d_fullcon(m.inner[0][0],
			m.inner[0][1],
			m.inner[0][2])));
}
