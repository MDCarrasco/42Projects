/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numeric_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:58:09 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 11:35:11 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t
	pf_getarg_signed_integer(va_list ap, t_modifier *m)
{
	intmax_t	arg;

	if (m->length == 'H')
		arg = (signed char)va_arg(ap, int);
	else if (m->length == 'h')
		arg = (short)va_arg(ap, int);
	else if (m->length == 'l')
		arg = va_arg(ap, long);
	else if (m->length == '7')
		arg = va_arg(ap, long long);
	else
		arg = va_arg(ap, int);
	return (arg);
}

static intmax_t
	pf_getarg_unsigned_integer(va_list ap, t_modifier *m)
{
	intmax_t	arg;

	if (m->length == 'H')
		arg = (unsigned char)va_arg(ap, unsigned);
	else if (m->length == 'h')
		arg = (unsigned short)va_arg(ap, unsigned);
	else if (m->length == 'l')
		arg = va_arg(ap, unsigned long);
	else if (m->length == '7')
		arg = va_arg(ap, unsigned long long);
	else
		arg = va_arg(ap, unsigned int);
	return (arg);
}

int
	pf_signed_integer(t_modifier *m, t_darray *d, va_list ap, int base)
{
	intmax_t	arg;
	int			res;

	arg = pf_getarg_signed_integer(ap, m);
	if (arg < 0)
		ft_darray_append(d, "-", 1);
	else if (m->booleans.n.plus)
		ft_darray_append(d, "+", 1);
	else if (m->booleans.n.space)
		ft_darray_append(d, " ", 1);
	if (arg == 0 && m->precision == 0)
		return (0);
	res = pf_itoa_base(d, arg, ABS(base), base < 0);
	if (m->quote)
		res += pf_culturization(d, ',');
	return (res);
}

int
	pf_unsigned_integer(t_modifier *m, t_darray *d, va_list ap, int base)
{
	uintmax_t	arg;
	int			res;

	arg = pf_getarg_unsigned_integer(ap, m);
	if (arg == 0 && m->booleans.n.alternate
		&& (m->conversion == 'x' || m->conversion == 'X'))
		d->size -= 2;
	if (arg == 0 && m->precision == 0)
		return (0);
	res = pf_uitoa_base(d, arg, ABS(base), base < 0);
	if (m->quote)
		res += pf_culturization(d, ',');
	return (res);
}
