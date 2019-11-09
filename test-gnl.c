/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-gnl.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 15:10:26 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/09 17:22:58 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

void	test(int fd, char **line, int testnb)
{
	int		ret;
	int		i;

	i = 0;
	while (i < testnb)
	{
		ret = get_next_line(fd, line);
		if (ret < 0)
			printf("Return %i\n", ret);
		else
			printf("%i - [%s]\n", ret, *line);
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
	int		ret;
	char	*line;

	if (ac == 2 && av[1][0] == 'g')
	{
		fd = open("get_next_line.c", O_RDONLY);
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			printf("l : %s\n", line);
			free(line);
		}
		free(line);
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
		printf("\nVery long lines :\n");
		fd = open("testfilesgnl/longlines", O_RDONLY);
		test(fd, &line, 4);
		return (0);
	}

	printf("BUFFER_SIZE : %i\n", BUFFER_SIZE);

	line = 0;
	printf("\nNegative fd :\n");
	test(-2, &line, 1);

	printf("\nNo file :\n");
	test(42, &line, 1);

	printf("\nEmpty file :\n");
	fd = open("testfilesgnl/empty", O_RDONLY);
	test(fd, &line, 1);

	printf("\nOnly newline :\n");
	fd = open("testfilesgnl/onlynewline", O_RDONLY);
	test(fd, &line, 2);

	printf("\nOnly a :\n");
	fd = open("testfilesgnl/onlya", O_RDONLY);
	test(fd, &line, 2);

	printf("\nOnly z + nl :\n");
	fd = open("testfilesgnl/onlyznl", O_RDONLY);
	test(fd, &line, 2);

	printf("\nLorem ipsum (+1 call) :\n");
	fd = open("testfilesgnl/loremipsum", O_RDONLY);
	test(fd, &line, 3);

	printf("\nLorem ipsum + nl :\n");
	fd = open("testfilesgnl/loremipsumnl", O_RDONLY);
	test(fd, &line, 2);

	printf("\nMultiple lines :\n");
	fd = open("testfilesgnl/multiplelines", O_RDONLY);
	test(fd, &line, 6);

	printf("\nMultiple short lines :\n");
	fd = open("testfilesgnl/multipleshortlines", O_RDONLY);
	test(fd, &line, 6);

	printf("\nMultiple lines, last line is long :\n");
	fd = open("testfilesgnl/multiplelineslonglast", O_RDONLY);
	test(fd, &line, 6);

	printf("\nOnly empty lines (4) :\n");
	fd = open("testfilesgnl/emptylines", O_RDONLY);
	test(fd, &line, 5);

	printf("\nSome empty lines (begin with full, finish with full) :\n");
	fd = open("testfilesgnl/someemptylines", O_RDONLY);
	test(fd, &line, 6);

	printf("\nSome empty lines (begin with empty, finish with empty) :\n");
	fd = open("testfilesgnl/someemptylines2", O_RDONLY);
	test(fd, &line, 8);

#if BUFFER_SIZE == 32

	printf("\n31 chars :\n");
	fd = open("testfilesgnl/31chars", O_RDONLY);
	test(fd, &line, 2);

	printf("\n30 chars + nl :\n");
	fd = open("testfilesgnl/30charsplusnl", O_RDONLY);
	test(fd, &line, 2);

	printf("\n32 chars :\n");
	fd = open("testfilesgnl/32chars", O_RDONLY);
	test(fd, &line, 2);

	printf("\n31 chars + nl :\n");
	fd = open("testfilesgnl/31charsplusnl", O_RDONLY);
	test(fd, &line, 2);

	printf("\n33 chars :\n");
	fd = open("testfilesgnl/33chars", O_RDONLY);
	test(fd, &line, 2);

	printf("\n32 chars + nl :\n");
	fd = open("testfilesgnl/32charsplusnl", O_RDONLY);
	test(fd, &line, 2);

	printf("\n33 chars + nl :\n");
	fd = open("testfilesgnl/33charsplusnl", O_RDONLY);
	test(fd, &line, 2);

	printf("\n30 chars + nl and small line :\n");
	fd = open("testfilesgnl/30charsplusnlmore", O_RDONLY);
	test(fd, &line, 3);

	printf("\n31 chars + nl and small line :\n");
	fd = open("testfilesgnl/31charsplusnlmore", O_RDONLY);
	test(fd, &line, 3);

	printf("\n32 chars + nl and small line :\n");
	fd = open("testfilesgnl/32charsplusnlmore", O_RDONLY);
	test(fd, &line, 3);

	printf("\n33 chars + nl and small line :\n");
	fd = open("testfilesgnl/33charsplusnlmore", O_RDONLY);
	test(fd, &line, 3);
#endif

	return (0);
}
