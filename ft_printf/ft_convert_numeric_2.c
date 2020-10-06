/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numeric_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:41:57 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 11:32:46 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_convert_spec_i(t_modifier *m, t_darray *d, va_list ap)
{
	return (pf_signed_integer(m, d, ap, 10));
}

int
	pf_convert_spec_n(t_modifier *m, t_darray *d, va_list ap)
{
	int	*arg;

	arg = va_arg(ap, void *);
	if (!arg)
		return (0);
	m->size = 0;
	m->precision = -1;
	if (m->length == 'H')
		*(char *)arg = (char)d->size;
	else if (m->length == 'h')
		*(short *)arg = (short)d->size;
	else if (m->length == 'l')
		*(long *)arg = (long)d->size;
	else if (m->length == '7')
		*(long long *)arg = (long long)d->size;
	else
		*(int *)arg = (int)d->size;
	return (0);
}
