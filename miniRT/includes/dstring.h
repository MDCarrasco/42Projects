/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstring.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:49:09 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:57:59 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DSTRING_H
# define DSTRING_H

# include <minirt.h>
# include <libft.h>

typedef struct		s_dstring
{
	char			*raw;
	t_ull			capacity;
	t_ull			size;
}					t_dstring;

t_bool				dstring_fullcon(t_dstring *output);
t_bool				dstring_push(t_dstring *self, const char *str);
t_bool				dstring_pushn(t_dstring *self, const char *str,
					t_ull length);

#endif
