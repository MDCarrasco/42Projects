/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 11:37:07 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:35:01 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

typedef unsigned long long t_ull;

typedef enum	e_bool
{
	false,
	true
}				t_bool;

typedef struct	s_vector
{
	t_ull		size;
	t_ull		capacity;
	t_ull		type_size;
	char		*raw;
}				t_vector;

t_bool			ft_vector_with_capacity(t_vector *self, t_ull type_size,
				t_ull capacity);
t_bool			ft_vector_new(t_vector *self, t_ull type_size);
t_bool			ft_vector_resize(t_vector *self, t_ull capacity);
t_bool			ft_vector_get(t_vector *self, t_ull index, void *out);
t_bool			ft_vector_push(t_vector *self, void *value);
t_bool			ft_vector_pop(t_vector *self, void *out);
t_bool			ft_vector_getr(t_vector *self, t_ull index, void **value);
t_bool			ft_vector_set(t_vector *self, t_ull index, void *value);
void			ft_vector_destroy(t_vector *self);

#endif
