/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:32:46 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 14:01:02 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include <libft.h>

typedef struct		s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_color;

t_color				color_fullcon(unsigned char r, unsigned char g,
					unsigned char b);
t_color				color_add(t_color a, t_color b);
t_color				color_mul(t_color a, t_color b, double mult);
unsigned int		color_as_uint(t_color color);

#endif
