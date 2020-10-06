/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_double_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:06:23 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 16:50:21 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int
	pf_rtoa(t_darray *d, long double x, int base, t_modifier *m)
{
	long double	frac;
	int			res;
	int			i;
	int			p;

	res = 1 + pf_itoa_base(d, (intmax_t)x, ABS(base), (base < 0));
	if (m->quote)
		res += pf_culturization(d, ',');
	res += pf_rtoa_dec_point(m, d);
	i = -1;
	frac = ft_modf(x);
	p = (m->precision == -1 ? 13 : m->precision);
	while (++i < p)
	{
		frac *= (long double)ABS(base);
		if (frac < 1)
			ft_darray_append(d, "0", 1);
		res++;
	}
	frac = ft_round_base(frac, ft_modf(frac), ABS(base));
	if (frac != 0)
		pf_uitoa_base(d, (long long)frac, ABS(base), base < 0);
	if (m->conversion == 'g' && !m->booleans.n.alternate)
		frac != 0 || m->precision >= 1 ? ft_darray_popzero(d, &res) : 0;
	return (res);
}

int
	pf_convert_spec_f(t_modifier *m, t_darray *d, va_list ap)
{
	double arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		ft_darray_append(d, "-", 1);
	else if (m->booleans.n.plus)
		ft_darray_append(d, "+", 1);
	else if (m->booleans.n.space)
		ft_darray_append(d, " ", 1);
	if (arg == 0 && m->precision == 0)
		return (0);
	if (m->precision == -1)
		m->precision = 6;
	if (arg == 1.0 / 0.0 || arg == 0.0 / 0.0)
	{
		if (arg == 1.0 / 0.0)
			ft_darray_append(d, "inf", 3);
		else
			ft_darray_append(d, "nan", 3);
		return (0);
	}
	return (pf_rtoa(d, ABS(arg), 10, m));
}

int
	pf_convert_spec_f_from_g(t_modifier *m, t_darray *d, long double arg)
{
	if (arg < 0)
		ft_darray_append(d, "-", 1);
	else if (m->booleans.n.plus)
		ft_darray_append(d, "+", 1);
	else if (m->booleans.n.space)
		ft_darray_append(d, " ", 1);
	if (arg == 0 && m->precision == 0)
		return (0);
	if (arg == 1.0 / 0.0 || arg == 0.0 / 0.0)
	{
		if (arg == 1.0 / 0.0)
			ft_darray_append(d, "inf", 3);
		else
			ft_darray_append(d, "nan", 3);
		return (0);
	}
	return (pf_rtoa(d, ABS(arg), 10, m));
}

int
	pf_convert_spec_e(t_modifier *m, t_darray *d, va_list ap)
{
	double arg;

	arg = va_arg(ap, double);
	if (arg < 0)
		ft_darray_append(d, "-", 1);
	else if (m->booleans.n.plus)
		ft_darray_append(d, "+", 1);
	else if (m->booleans.n.space)
		ft_darray_append(d, " ", 1);
	if (m->precision == -1)
		m->precision = 6;
	arg = ABS(arg);
	return (pf_signed_double_e(m, d, arg));
}

int
	pf_convert_spec_e_from_g(t_modifier *m, t_darray *d, long double arg)
{
	if (arg < 0)
		ft_darray_append(d, "-", 1);
	else if (m->booleans.n.plus)
		ft_darray_append(d, "+", 1);
	else if (m->booleans.n.space)
		ft_darray_append(d, " ", 1);
	arg = ABS(arg);
	return (pf_signed_double_e(m, d, arg));
}
