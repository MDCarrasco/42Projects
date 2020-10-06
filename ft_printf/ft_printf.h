/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 11:41:25 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:58:42 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include "./libft/libft.h"

# define FTPF_CV "cspdiuxXnfge"
# define FTPF_NUMERIC "pdiuxX"
# define FTPF_LM "hHl7"
# define FTPF_SWITCHES "0+- #"
# define NEW_MODIFIER (t_modifier){{{0, 0, 0, 0, 0}}, 0, 0, 0, 0, 0, -1};

typedef struct		s_modifier
{
	union
	{
		char		t[5];
		struct
		{
			char	zero;
			char	plus;
			char	minus;
			char	space;
			char	alternate;
		}			n;
	}				booleans;
	char			conversion;
	char			length;
	int				size;
	int				quote;
	int				mindex;
	int				precision;
}					t_modifier;

int					ft_printf(const char *fmt, ...);
int					ft_printf_fd(int fd, const char *fmt, ...);
int					ft_asprintf(char **ret, const char *fmt, ...);
int					ft_vprintf(const char *fmt, va_list ap);
int					ft_vprintf_fd(int fd, const char *fmt, va_list ap);
int					ft_vasprintf(char **ret, const char *s, va_list ap);
int					pf_convert(t_modifier *m, t_darray *d, va_list dap);
char				*pf_next_specifier(const char *s, t_darray *d);
int					pf_unsigned_integer(t_modifier *m,
					t_darray *d, va_list ap, int b);
int					pf_signed_integer(t_modifier *m,
					t_darray *d, va_list ap, int b);
int					pf_itoa_base(t_darray *d, intmax_t n, int b,
					unsigned char cap);
int					pf_uitoa_base(t_darray *d, uintmax_t n, int b,
					unsigned char cap);
int					pf_rtoa(t_darray *d, long double x, int b, t_modifier *m);
int					pf_rtoa_dec_point(t_modifier *m, t_darray *d);
int					pf_signed_double_e(t_modifier *m, t_darray *d,
					long double arg);
void				pf_signed_double_g(t_modifier *m, t_darray *d,
					long double arg);
int					pf_convert_spec_s(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_ws(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_p(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_d(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_i(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_u(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_x(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_cx(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_c(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_wc(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_n(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_f(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_f_from_g(t_modifier *m, t_darray *d,
					long double arg);
int					pf_convert_spec_e(t_modifier *m, t_darray *d, va_list ap);
int					pf_convert_spec_e_from_g(t_modifier *m, t_darray *d,
					long double arg);
void				pf_convert_spec_g(t_modifier *m, t_darray *d, va_list ap);
int					pf_culturization(t_darray *d, char c);
#endif
