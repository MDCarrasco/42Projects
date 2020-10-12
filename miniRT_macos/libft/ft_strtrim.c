/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:16:43 by micarras          #+#    #+#             */
/*   Updated: 2019/10/22 16:24:15 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_forward_count(const char *s1, const char *set)
{
	size_t		f_count;
	const char	*pt;

	f_count = 0;
	pt = set;
	while (*set)
	{
		if (*set == *s1)
		{
			f_count++;
			s1++;
			set = pt;
		}
		else
			set++;
	}
	return (f_count);
}

size_t	ft_backward_count(const char *s1, const char *set)
{
	size_t		b_count;
	const char	*end;
	const char	*pt;

	b_count = 0;
	end = s1 + ft_strlen(s1) - 1;
	pt = set;
	while (*set && b_count < ft_strlen(s1))
	{
		if (*set == *end)
		{
			b_count++;
			end--;
			set = pt;
		}
		else
			set++;
	}
	return (b_count);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	f_count;
	size_t	b_count;
	size_t	i;
	char	*result;
	int		true_len;

	if (!s1)
		return (NULL);
	if (!set)
		return (NULL);
	f_count = ft_forward_count(s1, set);
	b_count = ft_backward_count(s1, set);
	true_len = ft_strlen(s1) - (f_count + b_count);
	if (true_len < 0)
		true_len = 0;
	i = 0;
	if (!(result = malloc(sizeof(char) * (true_len + 1))))
		return (0);
	while (true_len--)
		result[i++] = s1[f_count++];
	result[i--] = '\0';
	return (result);
}
