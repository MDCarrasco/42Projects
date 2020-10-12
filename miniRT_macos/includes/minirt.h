/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 12:50:29 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 16:29:46 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <libft.h>

# define EPSILON 1e-6
# define LIGHT_MULT 40.0

# ifndef IS_BONUS
#  define IS_BONUS 0
#  define THREAD_COUNT 1
# else
#  ifndef THREAD_COUNT
#   define THREAD_COUNT 16
#  endif
# endif

void	panic(const char *message, t_bool include_errno);
void	assert(t_bool condition, const char *message, t_bool include_errno);
double	rad(double degrees);
double	deg(double radians);
t_bool	solve_quad(double abc[3], double x[2]);

#endif
