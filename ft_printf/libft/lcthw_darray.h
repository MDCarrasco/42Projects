/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcthw_darray.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:52:21 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:16:00 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LCTHW_DARRAY_H
# define LCTHW_DARRAY_H
# define LCTHW_DARRAY_LAST(A)	        ((A)->contents[(A)->end - 1])
# define LCTHW_DARRAY_FIRST(A)	        ((A)->contents[0])
# define LCTHW_DARRAY_END(A)	        ((A)->end)
# define LCTHW_DARRAY_COUNT(A)	        LCTHW_DARRAY_END(A)
# define LCTHW_DARRAY_MAX(A)	        ((A)->max)
# define LCTHW_DARRAY_FREE(E)           free((E))
# define LCTHWDA_DEFAULT_EXPAND_RATE	300
# define LCTHWDA_FACTOR                 2
# define LCTHWDA_INITIAL_SIZE           16
# include <stdlib.h>

typedef struct		s_lcthw_darray
{
	int				end;
	int				max;
	size_t			element_size;
	size_t			expand_rate;
	void			**contents;
}					t_lcthw_darray;

t_lcthw_darray		*lcthw_darray_create(size_t element_size,
					size_t initial_max);
void				*lcthw_darray_get(t_lcthw_darray *array, int i);
void				*lcthw_darray_new(t_lcthw_darray *array);
void				*lcthw_darray_remove(t_lcthw_darray *array, int i);
void				*lcthw_darray_pop(t_lcthw_darray *array);
void				lcthw_darray_set(t_lcthw_darray *array, int i, void *el);
void				lcthw_darray_destroy(t_lcthw_darray *array);
void				lcthw_darray_clear(t_lcthw_darray *array);
void				lcthw_darray_popzero(t_lcthw_darray *array, int *ans);
void				lcthw_darray_clear_destroy(t_lcthw_darray *array);
int					lcthw_darray_expand(t_lcthw_darray *array);
int					lcthw_darray_contract(t_lcthw_darray *array);
int					lcthw_darray_push(t_lcthw_darray *array, void *el);
int					lcthw_darray_resize(t_lcthw_darray *array, size_t newsize);
int					lcthw_darray_reserve(t_lcthw_darray *self, size_t size);
int					lcthw_darray_trim(t_lcthw_darray *array);

#endif
