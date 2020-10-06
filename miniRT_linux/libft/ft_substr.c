/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:59:37 by micarras          #+#    #+#             */
/*   Updated: 2019/10/22 16:20:45 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start > len)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (start--)
		s++;
	ft_strlcpy(str, s, len + 1);
	str[len] = '\0';
	return (str);
}
