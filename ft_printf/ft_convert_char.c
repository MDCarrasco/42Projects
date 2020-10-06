/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:19:28 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 10:49:37 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int
	pf_widechar_exception(wchar_t *c)
{
	if (*c >= 0xD800 && *c <= 0xDBFF)
		return (-1);
	if (*c >= 0xDC00 && *c <= 0xDFFF)
		return (-1);
	if (*c < 0)
		return (-1);
	if (MB_CUR_MAX == 1 && *c >= 0x100)
		return (-1);
	if (MB_CUR_MAX == 1 && (*c >= 0x80 && *c < 0x100))
		*c = *c - 256;
	return (1);
}

int
	pf_convert_spec_wc(t_modifier *m, t_darray *d, va_list ap)
{
	wint_t	arg;
	size_t	res;

	(void)m;
	arg = va_arg(ap, wint_t);
	m->precision = -1;
	ft_darray_reserve(d, 4);
	if (arg >= 0xD800 && arg <= 0xDBFF)
		return (-1);
	if (arg >= 0xDC00 && arg <= 0xDFFF)
		return (-1);
	if (MB_CUR_MAX == 1 && arg >= 0x100)
		return (-1);
	if (MB_CUR_MAX == 1 && (arg >= 0x80 && arg < 0x100))
		arg = arg - 256;
	res = ft_widetoa((char *)FT_DARRAY_END(d), arg);
	if (res == 0)
		return (-1);
	d->size += res;
	return ((int)res);
}

int
	pf_convert_spec_ws(t_modifier *m, t_darray *d, va_list ap)
{
	wchar_t	*arg;
	size_t	len;
	wchar_t	*ptr;

	arg = va_arg(ap, wchar_t *);
	if (arg == NULL)
		arg = L"(null)";
	ptr = arg;
	while (*ptr)
	{
		if (pf_widechar_exception(ptr) == -1)
			return (-1);
		ptr++;
	}
	ft_darray_reserve(d, 4 * (ptr - arg));
	if (m->precision >= 0)
		len = ft_wstrnconv((char *)FT_DARRAY_END(d), arg, m->precision);
	else
		len = ft_wstrconv((char *)FT_DARRAY_END(d), arg);
	m->precision = -1;
	d->size += len;
	return (len);
}

int
	pf_convert_spec_c(t_modifier *m, t_darray *d, va_list ap)
{
	unsigned char	arg;

	(void)m;
	if (m->length == 'l')
		return (pf_convert_spec_wc(m, d, ap));
	else
		arg = (char)va_arg(ap, int);
	m->precision = -1;
	ft_darray_append(d, (void *)&arg, 1);
	return (1);
}

int
	pf_convert_spec_s(t_modifier *m, t_darray *d, va_list ap)
{
	char	*arg;
	int		res;

	if (m->length == 'l')
		return (pf_convert_spec_ws(m, d, ap));
	else
		arg = va_arg(ap, char *);
	if (arg == NULL)
		arg = "(null)";
	res = (m->precision >= 0 ? MIN(ft_strlen(arg), (size_t)m->precision)
		: ft_strlen(arg));
	m->precision = -1;
	ft_darray_append(d, (void *)arg, res);
	return (res);
}
