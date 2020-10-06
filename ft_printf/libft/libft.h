/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:14:13 by micarras          #+#    #+#             */
/*   Updated: 2019/11/26 13:59:01 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(V)             ((V) < 0 ? -(V) : (V))
# define MIN(X, Y)          (((X) < (Y)) ? (X) : (Y))
# define _MIN2(A, B)        ((A) < (B) ? (A) : (B))
# include "lcthw_darray.h"
# include "ft_darray.h"
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_ishexdigit(char c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_atoi(const char *str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_intlen(int a);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_wstrlen(const wchar_t *wstr);
size_t				ft_widetoa(char *buff, wint_t w);
size_t				ft_wstrconv(char *buff, const wchar_t *wstr);
size_t				ft_wstrnconv(char *buff, const wchar_t *wstr, size_t n);
double				ft_modf(double num);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_puthex(unsigned long long n, unsigned int uppercase);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_calloc(size_t count, size_t size);
void				*ft_realloc(void *ptr, size_t size);
char				*ft_strrchr(const char *str, int c);
char				*ft_strchr(const char *str, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_seek(const char *haystack, const char *needle);
int					is_in(char i, const char *str);
char				*ft_strdup(const char *s1);
char				*ft_substr(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				**ft_split(const char *s, char c);
char				*ft_strsub(const char *s, unsigned int	start, size_t len);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
void				lcthw_pushhex(unsigned long long n, unsigned int uppercase,
							t_lcthw_darray *a);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **alst, t_list *new);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
long int			ft_round_base(double x, double f, int b);

#endif
