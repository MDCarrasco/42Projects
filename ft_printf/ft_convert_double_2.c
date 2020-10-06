/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:23:02 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 16:43:14 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	pf_finde(long double *arg)
{
	int			e;
	long double	argb;

	e = 0;
	argb = *arg;
	while (argb > 0 && argb < 1)
	{
		argb = argb * 10;
		e--;
	}
	while (argb > 10)
	{
		argb = argb / 10;
		e++;
	}
	return (e);
}

int
	pf_rtoa_dec_point(t_modifier *m, t_darray *d)
{
	int res;

	res = 0;
	if (m->precision == 0)
	{
		if (m->booleans.n.alternate)
		{
			ft_darray_append(d, ".", 1);
			++res;
		}
		else
			return (res);
	}
	else
	{
		ft_darray_append(d, ".", 1);
	}
	return (res);
}

int
	pf_signed_double_e(t_modifier *m, t_darray *d, long double arg)
{
	int			res;
	int			e;
	const char	*c = "e";

	e = pf_finde(&arg);
	if (((int)((arg) * 10) % 10) != 0)
	{
		res = ft_darray_append(d, "0.", 2);
		arg = arg * 10;
	}
	else
		while (arg > 0 && arg < 1)
			arg = arg * 10;
	while (arg > 10)
		arg = arg / 10;
	res = pf_rtoa(d, ABS(arg), 10, m);
	res += ft_darray_append(d, c, 1);
	if (e >= 0)
		res += ft_darray_append(d, "+", 1);
	else
		res += ft_darray_append(d, "-", 1);
	if (ABS(e) < 10)
		res += ft_darray_append(d, "0", 1);
	pf_itoa_base(d, e, 10, 0);
	return (res);
}

void
	pf_signed_double_g(t_modifier *m, t_darray *d, long double arg)
{
	int	e;

	if (m->precision == -1)
		m->precision = 6;
	else if (m->precision == 0)
		m->precision = 1;
	e = pf_finde(&arg);
	if (m->precision > e && e >= -4)
	{
		m->precision = m->precision - (e + 1);
		pf_convert_spec_f_from_g(m, d, arg);
	}
	else
	{
		m->precision--;
		pf_convert_spec_e_from_g(m, d, arg);
	}
	return ;
}

void
	pf_convert_spec_g(t_modifier *m, t_darray *d, va_list ap)
{
	double arg;

	arg = va_arg(ap, double);
	pf_signed_double_g(m, d, arg);
	return ;
}
