/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarras <micarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 10:54:49 by micarras          #+#    #+#             */
/*   Updated: 2020/06/29 15:33:45 by micarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#define STRLEN(x)	printf("`%s` = %lu (%lu)\n", x, ft_strlen(x), strlen(x));
#define STRCMP(a, b) printf("`%s`:`%s` = %d (%d)\n", a, b, ft_strcmp(a, b), strcmp(a, b));
#define WRITE(s, x) printf("^%ld (`%s`:%ld)\n", ft_write(STDOUT_FILENO, s, x), s, x);
#define READ(b, x) r = ft_read(STDIN_FILENO, buffer, x); printf("`%s`:%ld\n", buffer, r);
#define DUP(s) tmp = ft_strdup(s); printf("`%s` (`%s`)\n", tmp, s); free(tmp); tmp = NULL;

size_t 		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);
int			ft_strcmp(const char *s1, const char *s2);
ssize_t		ft_write(int fd, const void *buf, size_t nbyte);
ssize_t		ft_read(int fd, void *buf, size_t nbyte);
char		*ft_strdup(const char *src);

int
	main(void)
{
	int		fd;
	int		fd2;
	int		i;
	int		errno;
	long	r;
	char	buffer[100];
	char	*tmp;
	char	*tmp2;
	void	*bad_address;

	errno = 0;
	bad_address = (void *)0xFFFFFFFC;
	i = -1;
	while (++i < 100)
		buffer[i] = 0;

	printf("--strlen\n");
	STRLEN("");
	STRLEN("toto");
	STRLEN("totototo");
	STRLEN("0123456789abcdef");
	STRLEN("42");
	STRLEN("1");
	printf("-done\n");

	printf("\n--strcpy\n");
	printf("`%s` (`toto`)\n", ft_strcpy(buffer, "toto"));
	printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
	printf("`%s` (`long message`)\n", ft_strcpy(buffer, "long message"));
	printf("`%s` (NULL > not modified)\n", ft_strcpy(buffer, NULL));
	printf("-done\n");
	
	printf("\n--strcmp\n");
	STRCMP("", "");
	STRCMP("toto", "toto");
	STRCMP("", "toto");
	STRCMP("toto", "");
	STRCMP("toto", "totobar");
	printf("hey there dude---------------\n");
	STRCMP("\xff\xff", "\xff");
	printf("`%s`:`%p` = %d\n", "TOTO", NULL, ft_strcmp("TOTO", NULL));
	printf("`%p`:`%s` = %d\n", NULL, "TOTO", ft_strcmp(NULL, "TOTO"));
	printf("`%p`:`%p` = %d\n", NULL, NULL, ft_strcmp(NULL, NULL));
	printf("-done\n");
	
	while (--i >= 0)
		buffer[i] = 0;

	printf("\n--write\n");
	WRITE("toto", 4L);
	WRITE("totototo", 4L);
	WRITE("totototo", 8L);
	WRITE("toto", 2L);

	fd = open("fileout.txt", O_RDWR | O_CREAT, 0644);
	printf("^%ld (`%s`:%ld) written in test file.\n", ft_write(fd, "toto", 4L),
			"toto", 4L);
	close(fd);
	fd = open("fileout.txt", O_RDONLY);
	r = read(fd, buffer, 4);
	close(fd);
	printf("file content : `%s`:%ld\n", buffer, r);
	

	printf("\n--errno_tests\n");
	printf("TEST 1 - errno should be 9 EBADF !\n");
	printf("yours-----------------------\n");
	fd2 = open("BADfileout.txt", O_RDONLY | O_CREAT, 0444);
	printf("^%ld trying to write (`%s`:%ld) in a O_RDONLY file.\n",
			ft_write(fd2, "toto", 4L), "toto", 4L);
	printf("errno = %d\n", errno);
	close(fd2);
	printf("real-----------------------\n");
	fd2 = open("BADfileout.txt", O_RDONLY | O_CREAT, 0444);
	printf("^%ld trying to write (`%s`:%ld) in a O_RDONLY file.\n",
			write(fd2, "toto", 4L), "toto", 4L);
	printf("errno = %d\n\n", errno);
	close(fd2);

	printf("TEST 2 - errno should be 14 EFAULT !\n");
	printf("yours-----------------------\n");
	fd2 = open("BADfileout2.txt", O_RDWR | O_CREAT, 0644);
	printf("^%ld trying to write something" \
			" from a forbidden address to a file.\n", \
			ft_write(fd2, bad_address, 4L));
	printf("errno = %d\n", errno);
	close(fd2);
	printf("real-----------------------\n");
	fd2 = open("BADfileout2.txt", O_RDWR | O_CREAT, 0644);
	printf("^%ld trying to write something" \
			" from a forbidden address to a file.\n",
			write(fd2, bad_address, 4L));
	printf("errno = %d\n", errno);
	close(fd2);
	printf("-done\n\n");

	while (++i < 100)
		buffer[i] = 0;

	printf("\n--read (Makefile)\n");
	READ(buffer, 50);
	READ(buffer, 25);
	READ(buffer, 4);
	READ(buffer, 26);
	READ(buffer, 14);
	READ(buffer, 0);

	printf("\n--errno_tests\n");
	printf("TEST 1 - errno should be 9 EBADF !\n");
	printf("yours-----------------------\n");
	r = ft_read(-200, buffer, 4);
	printf("`%s`:%ld\n", buffer, r);
	printf("errno = %d\n", errno);
	printf("real-----------------------\n");
	r = read(-200, buffer, 4);
	printf("`%s`:%ld\n", buffer, r);
	printf("errno = %d\n\n", errno);
	printf("TEST 2 - errno should be 14 EFAULT !\n");
	printf("yours-----------------------\n");
	r = ft_read(STDIN_FILENO, bad_address, 4);
	printf("`%s`:%ld\n", buffer, r);
	printf("errno = %d\n", errno);
	printf("real-----------------------\n");
	r = read(STDIN_FILENO, bad_address, 4);
	printf("`%s`:%ld\n", buffer, r);
	printf("errno = %d\n", errno);
	printf("-done\n");

	printf("\n--ft_strdup\n");
	tmp2 = ft_strdup("toto");
	DUP(tmp2);
	free(tmp2);
	DUP("totobar");
	DUP("long message");
	DUP("");
	tmp2 = ft_strdup(NULL);
	DUP(tmp2);
	free(tmp2);
	tmp2 = NULL;
	printf("-done\n");
	
	return (0);
}
