/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_darray.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 19:16:44 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 14:02:12 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DARRAY_H
# define FT_DARRAY_H

# include <stddef.h>

/*
** |		----------=====  Array<T>  =====----------
** The following functions allows one to manipulate a collection of objects,
** not bothering about malloc.
** It is inspired by the C++ "Vector<T>"
** -
** In C++ and Java, one would declare such an object with
** the template/generics syntax :
** |	Vector<SomeType> variable = _new Vector<SomeType>();
** -
** Here in C,
** |	t_darray	variable = NEW_FT_DARRAY(t_some_type);
*/

typedef struct	s_darray
{
	void		*data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_darray;

/*
** |		----------===== public: =====----------
*/

/*
** Array::_new
** -
** Failsafe constructor, no memory is allocated.
** -
** _T_ should be the type to be stored in the array.
** -
** Returns an array, correctly initialised.
*/

# define NEW_FT_DARRAY(T) (t_darray){NULL, 0, 0, sizeof(T)}

/*
** Array::_new
** -
** Constructor that tries a first malloc.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
*/

t_darray		ft_darray_new(size_t type_size);

/*
** Array::alloc
** -
** Allocates an array and its data.
** -
** _type_size_ should equal to the returned value of sizeof(T)
** -
** Returns the allocated array,
** or NULL if malloc failed.
*/

t_darray		*ft_darray_alloc(size_t type_size);

/*
** Array::apppend
** -
** Could be called "add all" like in Java.
** Adds _datalen_ elements to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _datalen_ should be the number of elements stored in _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int				ft_darray_append(
				t_darray *self, void const *data, size_t datalen);

/*
** Array::apppend_free
** -
** Could be called "add all" like in Java.
** Adds _datalen_ elements to _self_. then free _data_
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _datalen_ should be the number of elements stored in _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int				ft_darray_append_free(
				t_darray *self, void *data, size_t datalen);

/*
** Array::apppend_char
** -
** Could be called "add all" like in Java.
** Adds 1 elements to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type char
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int				ft_darray_append_char(t_darray *self, char data);

/*
** Array::insert
** -
** Adds _datalen_ elements at index _index_ to _self_.
** May fail if malloc does.
** -
** _data_ should be a variable of type T* casted to void*.
** _datalen_ should be the number of elements stored in _data_.
** _index_ is the future index of the first element of _data_.
** -
** Returns a status :
** 0 in case of success,
** 1 if malloc failed.
*/

int				ft_darray_insert(
				t_darray *self, void const *data, size_t datalen, size_t index);

/*
** Array::reserve
** -
** When one has an estimation of the number of elements that they will add
** to the array, using reserve will prevent multiple re-allocations,
** and ensure the best complexity.
** Indeed this function makes sure that the array has enough room
** for _size_ elements to be added.
** -
** _size_ is the number of elements that are planned to be added.
** -
** Returns a status :
** 0 in case of success,
** 1 if a re-alloc failed, and leaves the array as-is.
*/

int				ft_darray_reserve(t_darray *self, size_t size);

/*
** Array::trim
** -
** Could be called "shrink to fit" as it is in C++.
** This function is meant to be called when no more
** elements are expected to be appended to the array.
** Usually there are extra bytes allocated, to ensure
** a low complexity and few system calls, but this
** functions allocates the minimum number of bytes for
** all elements to fit.
** -
** Returns :
** 0 if the malloc succeeded,
** 1 otherwise.
*/

int				ft_darray_trim(t_darray *self);

/*
** Array::pop_back
** -
** Removes at most _len_ elements at the end.
** -
** _len_ is the number of elements to be removed.
*/

void			ft_darray_popback(t_darray *self, size_t len);

/*
** Array::pop_zero
** -
** Removes all zero from the end
** -
** ans total size after remove
*/

void			ft_darray_popzero(t_darray *self, int *ans);

/*
** Array::pop_zero
** -
** Removes all zero from the end for hex
** -
** ans total size after remove
*/

void			ft_darray_popzerohex(t_darray *self, int *ans);

/*
** Array::pop_back w/ function
** -
** Same as pop_back, but provides a way to avoid leaks by freeing
** contents pointed by the poped elements.
** -
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single element's
** contents from its address.
*/

void			ft_darray_popbackf(
				t_darray *self, size_t len, void (*del)(void *));

/*
** Array::pop_index
** -
** Removes at most _len_ elements starting at _index_.
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/

int				ft_darray_popindex(t_darray *self, size_t index, size_t len);

/*
** Array::pop_index w/ function
** -
** Same as ft_darray_popindex, but with a way to free cleanly the removed
** elements.
** -
** _index_ is the index of the first element to be removed.
** _len_ is the number of elements to be removed.
** _del_ is a function that knows how to properly free a single
** element's contents from its address.
** -
** Returns a status :
** 0 for success
** 1 if the index is invalid.
*/

int				ft_darray_popindexf(
				t_darray *self, size_t index, size_t len, void (*del)(void *));

/*
** Array::substitute
** -
** replace a part of _self_ by _new_
** -
**       |---| <-len
** "echo $USER is cool"
**       |   \----\
** "echo john_smith is cool"
**       ^index
** -
** Returns a status
** 1 in case of failure (malloc)
** 0 otherwise.
*/

int				ft_darray_substitute(
				t_darray *self, size_t index, size_t len, t_darray *da_new);

/*
** Array::pop_front
** -
** Might be clearer sometimes
*/

# define FT_DARRAY_POPFRONT(A,N) ft_darray_popindex(A, 0, N)

/*
** Array::index_check
** -
** Checks if the provided index is a valid one.
** -
** Returns a boolean :
** 0 if _I_ is strictly negative or is greater than the number of elements
** 1 otherwise
*/

# define FT_DARRAY_INDEX_CHECK(A,I) (0 <= (I) && (I) < (A)->size)

/*
** Array::get
** -
** Returns the address of the element of the array of index _I_
** Just be sure that such an element exists
*/

# define FT_DARRAY_GET(A,I) (FT_DARRAY_START(A) + FT_DARRAY_OFFSET(A,I))

/*
** Array::get_typed
** -
** Same as get, but casted to a pointer of the type.
*/

# define FT_DARRAY_GETT(T,A,I) ((T*)FT_DARRAY_GET(A,I))

/*
** Array::get_typed_safe
** -
** Same as get_safe, but casted to a pointer of the type.
*/

# define FT_DARRAY_GETTS(T,A,I) ((T*)FT_DARRAY_GETS(A,I))

/*
** Array::get_element
** -
** returns the element of index _I_
*/

# define FT_DARRAY_GETL(T,A,I) (*FT_DARRAY_GETT(T,A,I))

/*
** Array::index_from_pointer
** -
** _P_ is an element of the array whose index is seeked
*/

# define FT_DARRAY_IFP(A,P) ((((void *)P) - (A)->data) / (A)->type_size)

/*
** Iterator<Array>::_new
** -
** Returns an iterator over an array.
*/

# define FT_DARRAY_ITERATOR(A) (FT_DARRAY_START(A) - FT_DARRAY_STEP(A))

/*
** Iterator<Array>::Start
** -
** Returns the start of the array.
*/

# define FT_DARRAY_START(A) ((A)->data)

/*
** Iterator<Array>::End
** -
** Returns the end of the array
*/

# define FT_DARRAY_END(A) ((A)->data + (A)->size * (A)->type_size)

/*
** Iterator<Array>::Last
** -
** Returns the last element of the array (char *)
*/

char			*ft_darray_last(t_darray *d);

/*
** Iterator<Array>::Step
** -
** Allows one to go from the address of an element to the next.
*/

# define FT_DARRAY_STEP(A) ((A)->type_size)

/*
** Iterator<Array>::offset
** -
** Allows one to go from the address of an element to another.
*/

# define FT_DARRAY_OFFSET(A,I) ((I) * FT_DARRAY_STEP(A))

/*
** Iterator<Array>::next
** -
** Increments the iterator, for it to point to the next element.
** -
** Returns the _new value of the iterator.
*/

# define FT_DARRAY_NEXT(A,IT) ((IT) += FT_DARRAY_STEP(A))

/*
** Iterator<Array>::has_next
** -
** Increments the iterator, for it to point to the next element.
** -
** Returns a boolean indicating if the end of the array was reached.
*/

# define FT_DARRAY_HASNEXT(A,IT) (FT_DARRAY_NEXT(A,IT) < FT_DARRAY_END(A))

/*
** Array::string
** -
** toString
** description
** -
** _f_ converts an element to a string.
** -
** Returns a string representing the given array.
*/

char			*ft_darray_string(t_darray *self, char *(*f)(void *));

/*
** |		----------===== private: =====----------
*/

/*
** The initial size is the number of elements a _new array will be able
** to store before allocating more memory.
*/

# define FT_DARRAY_INITIAL_SIZE 16

/*
** When reaching its capacity, an array will re-allocate memory,
** using this factor to grow relatively to its previous size.
*/

# define FT_DARRAY_FACTOR 2

/*
** Array::_resize
** -
** No subtlety, just resizes the underlying array, no matter the consequences.
** However, in case of a malloc fail, the array is left untouched.
*/

int				ft_darray_resize(t_darray *self, size_t new_size);

/*
** Array::_swap
** -
** swaps an array segment with what follows.
** very specific function, not useful for standard cases.
** -
** "   -1415920000"
** -swap(4, 10)->
** "   -0000141592"
** -swap(0, 4)->
** "-0000141592   "
*/

void			ft_darray_swap(t_darray *self, size_t before, size_t after);

/*
** Array::clear
** -
** Frees the underlying data, but leaves the array usable :
** one might still call the append function, the array was only
** emptied.
*/

void			ft_darray_clear(t_darray *self);

/*
** Array::printdata
** -
** Print contents of t_darray with data type int
*/

void			ft_darray_printdata_int(t_darray *v);
#endif
