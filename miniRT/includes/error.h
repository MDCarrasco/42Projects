/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 16:20:41 by micarras          #+#    #+#             */
/*   Updated: 2020/06/03 17:36:37 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>

void	panic(const char *message, t_bool include_errno);
void	assert(t_bool condition, const char *message, t_bool include_errno);

#endif
