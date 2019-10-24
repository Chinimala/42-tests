/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-gnl-multiplefd.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/21 11:40:24 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 15:17:23 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

void	test(int fd, char **line, int testnb)
{
	int		ret;
	char	*ptr;
	int		i;

	ptr = *line;
	i = 0;
	while (i < testnb)
	{
		ret = get_next_line(fd, line);
		if (ret < 0)
			printf("Return %i\n", ret);
		else
			printf("Fd %i - %i - [%s]\n", fd, ret, *line);
		if (*line)
			free(*line);
		else
			printf("Error : line = 0\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	char	*line;

	line = 0;
	if (ac == 2 && av[1][0] == 'g')
	{
		fd = open("get_next_line_bonus.c", O_RDONLY);
		fd2 = open("get_next_line_bonus.h", O_RDONLY);
		fd3 = open("get_next_line_utils_bonus.c", O_RDONLY);
		printf("\nFd 1 :\n");
		test(fd, &line, 13);
		printf("\nFd 2 :\n");
		test(fd2, &line, 13);
		printf("\nFd 3 :\n");
		test(fd3, &line, 13);
		printf("\nFd 1 :\n");
		test(fd, &line, 13);
		printf("\nFd 2 :\n");
		test(fd2, &line, 13);
		printf("\nFd 2 :\n");
		test(fd2, &line, 13);
		printf("\nFd 3 :\n");
		test(fd3, &line, 13);
		printf("\nFd 3 :\n");
		test(fd3, &line, 13);
		printf("\nFd 1 :\n");
		test(fd, &line, 13);
		return (0);
	}
	else if (ac == 2 && av[1][0] == '0')
	{
		while ((ret = get_next_line(0, &line)) == 1)
		{
			printf("l : %s\n", line);
			free(line);
		}
		free(line);
		return (0);
	}
	else if (ac == 2 && av[1][0] == 'l')
	{
		printf("\nVery long lines and lorem ipsum :\n");
		fd = open("testfilesgnl/longlines", O_RDONLY);
		fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
		printf("\nFd 1 :\n");
		test(fd, &line, 1);
		printf("\nFd 2 :\n");
		test(fd2, &line, 1);
		printf("\nFd 1 :\n");
		test(fd, &line, 1);
		printf("\nFd 2 :\n");
		test(fd2, &line, 1);
		return (0);
	}

	printf("BUFFER_SIZE : %i\n", BUFFER_SIZE);

	printf("\nMissing file alterning with some short lines :\n");
	fd = open("testfilesgnl/multipleshortlines", O_RDONLY);
	test(fd, &line, 1);
	ret = get_next_line(42, &line);
	if (ret < 0)
		printf("Return %i\n", ret);
	else
		printf("%i - [%s]\n", ret, line);
	test(fd, &line, 1);

	printf("\nEmpty file alterning with some short lines :\n");
	fd = open("testfilesgnl/empty", O_RDONLY);
	fd2 = open("testfilesgnl/multipleshortlines", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);
	test(fd2, &line, 1);

	printf("\nTwo simple files alterning :\n");
	fd = open("testfilesgnl/loremipsum", O_RDONLY);
	fd2 = open("testfilesgnl/multipleshortlines", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);
	test(fd2, &line, 1);

	printf("\nThree simple files alterning :\n");
	fd = open("testfilesgnl/loremipsum", O_RDONLY);
	fd2 = open("testfilesgnl/multipleshortlines", O_RDONLY);
	fd3 = open("testfilesgnl/onlyznl", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd3, &line, 1);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd3, &line, 1);
	test(fd, &line, 1);
	
#if BUFFER_SIZE == 32

	printf("\n31 chars :\n");
	fd = open("testfilesgnl/31chars", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);

	printf("\n30 chars + nl :\n");
	fd = open("testfilesgnl/30charsplusnl", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);

	printf("\n32 chars :\n");
	fd = open("testfilesgnl/32chars", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);

	printf("\n31 chars + nl :\n");
	fd = open("testfilesgnl/31charsplusnl", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);

	printf("\n33 chars :\n");
	fd = open("testfilesgnl/33chars", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);

	printf("\n32 chars + nl :\n");
	fd = open("testfilesgnl/32charsplusnl", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);

	printf("\n33 chars + nl :\n");
	fd = open("testfilesgnl/33charsplusnl", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 1);

	printf("\n30 chars + nl and small line :\n");
	fd = open("testfilesgnl/30charsplusnlmore", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 2);

	printf("\n31 chars + nl and small line :\n");
	fd = open("testfilesgnl/31charsplusnlmore", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 2);

	printf("\n32 chars + nl and small line :\n");
	fd = open("testfilesgnl/32charsplusnlmore", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 2);

	printf("\n33 chars + nl and small line :\n");
	fd = open("testfilesgnl/33charsplusnlmore", O_RDONLY);
	fd2 = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 1);
	test(fd2, &line, 1);
	test(fd, &line, 2);
#endif

	return (0);
}
