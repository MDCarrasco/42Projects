/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numeric_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:22:47 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 11:31:03 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_convert_spec_d(t_modifier *m, t_darray *d, va_list ap)
{
	return (pf_signed_integer(m, d, ap, 10));
}

int
	pf_convert_spec_u(t_modifier *m, t_darray *d, va_list ap)
{
	return (pf_unsigned_integer(m, d, ap, 10));
}

int
	pf_convert_spec_x(t_modifier *m, t_darray *d, va_list ap)
{
	if (m->booleans.n.alternate)
		ft_darray_append(d, "0x", 2);
	return (pf_unsigned_integer(m, d, ap, 16));
}

int
	pf_convert_spec_cx(t_modifier *m, t_darray *d, va_list ap)
{
	if (m->booleans.n.alternate)
		ft_darray_append(d, "0X", 2);
	return (pf_unsigned_integer(m, d, ap, -16));
}

int
	pf_convert_spec_p(t_modifier *m, t_darray *d, va_list ap)
{
	(void)m;
	ft_darray_append(d, "0x", 2);
	m->length = '7';
	return (pf_unsigned_integer(m, d, ap, 16));
}
