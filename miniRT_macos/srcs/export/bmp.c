/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 14:27:25 by micarras          #+#    #+#             */
/*   Updated: 2020/06/15 13:06:57 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rendering.h>

t_bool
	output_bmp(t_vector *colors, unsigned int width, unsigned int height)
{
	static const int	zeroed[32];
	int					fd;
	ssize_t				res;
	t_ull				i;
	t_color				*color;

	fd = open("./save/output.bmp", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (false);
	res = write(fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	res += write(fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	res += write(fd, &width, 4);
	res += write(fd, &height, 4);
	res += write(fd, "\x01\x00\x18\x00", 4);
	res += write(fd, zeroed, 24);
	if (res != 54)
		return (false);
	i = height;
	while (i > 0 && res != -1)
	{
		i -= 1;
		(void)ft_vector_getr(colors, i * width, (void **)&color);
		res = write(fd, color, width * sizeof(t_color));
	}
	return (true);
}
