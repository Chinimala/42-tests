/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:56:13 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/24 11:12:20 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "libft.h"

void	ft_clean(void *content)
{
	printf("Freeing : %i\n", *((int*)content));
}

void	ft_del(void *content)
{
	*(int*)content = 0;
	return ;
}

void	ft_it(void *content)
{
	printf("%i ", *((int*)content));
}

void	*ft_m(void *content)
{
	void	*newcontent;

	newcontent = malloc(sizeof(int));
	*((int*)newcontent) = *((int*)content) + 10;
	return (newcontent);
}

char	ft_test(unsigned int i, char c)
{
	i = 0;
	return (c - 32);
}

int		main(void)
{
	printf("Test de ft_memset :\n");
	char s[100] = "aaaaa";
	char sbis[100] = "aaaaa";
	if (!strcmp(memset(s, 'z', 3), ft_memset(sbis, 'z', 3)))
		printf("OK\n");
	else
		printf("Failed : expected '%s', got '%s'.\n", s, sbis);

	printf("Test de ft_bzero :\n");
	strcpy(sbis, s);
	bzero(s, 3);
	ft_bzero(sbis, 3);
	int		i;
	i = 0;
	while (i < 5 && s[i] == sbis[i])
		i++;
	if (i == 5)
		printf("OK\n");
	else
		printf("Failed : expected [%c][%c][%c][%c][%c], got [%c][%c][%c][%c][%c].\n", s[0], s[1], s[2], s[3], s[4], sbis[0], sbis[1], sbis[2], sbis[3], sbis[4]);

	printf("Test de ft_memcpy :\n");
	strcpy(sbis, s);
	if (!strcmp(memcpy(s, "source", 3), ft_memcpy(sbis, "source", 3)) && !strcmp(memcpy(s, "2emesource", 8), ft_memcpy(sbis, "2emesource", 8)))
		printf("OK\n");
	else
		printf("Failed : expected '%s', got '%s'.\n", s, sbis);

	printf("Test de ft_memccpy :\n");
	char dst[100] = "destination";
	char dst2[100] = "destination";
	if (memccpy(dst, "source", ' ', 8) == ft_memccpy(dst2, "source", ' ', 8) && !strcmp(dst, dst2) && (char*)memccpy(dst, "2emesource", 'e', 8) - dst == (char*)ft_memccpy(dst2, "2emesource", 'e', 8) - dst2 && !strcmp(dst, dst2))
		printf("OK\n");
	else
		printf("Failed.\n");

	printf("Test de ft_memmove :\n");
	char s1[] = "string test";
	char s2[] = "string test";
	if (!strcmp(memmove(s1, s1 + 3, 5), ft_memmove(s2, s2 + 3, 5)) && !strcmp(memmove(s1 + 3, s1, 5), ft_memmove(s2 + 3, s2, 5)))
		printf("OK\n");
	else
		printf("Failed (tests : ft_memmove(s, s + 3, 5) and ft_memmove(s + 3, s, 5)).\n");

	printf("Test de ft_memchr : \n");
	if (memchr("source", 'r', 2) == ft_memchr("source", 'r', 2) && !strcmp(memchr("source", 'r', 5), ft_memchr("source", 'r', 5)))
		printf("OK\n");
	else
		printf("Failed.\n");

	printf("\nTest de ft_memcmp : \n");
	printf("0 : %d\n", ft_memcmp("test", "test", 4));
	printf("negatif : %d\n", ft_memcmp("test", "test2", 5));
	printf("0 : %d\n", ft_memcmp("test", "test2", 4));
	printf("positif : %d\n", ft_memcmp("\200", "\0", 4));
	printf("positif : %d\n", ft_memcmp("tesu", "test", 6));

	printf("\nTest de ft_strlen : \n");
	printf("0 : %lu\n", ft_strlen(""));
	printf("5 : %lu\n", ft_strlen("12345"));

	printf("\nTest de ft_isalpha :\n");
	printf("0 : %d\n", ft_isalpha(' '));
	printf("1 : %d\n", ft_isalpha('p'));
	printf("1 : %d\n", ft_isalpha('H'));
	printf("0 : %d\n", ft_isalpha(2));
	printf("0 : %d\n", ft_isalpha('8'));

	printf("\nTest de ft_isdigit :\n");
	printf("0 : %d\n", ft_isdigit(' '));
	printf("0 : %d\n", ft_isdigit('p'));
	printf("0 : %d\n", ft_isdigit('H'));
	printf("0 : %d\n", ft_isdigit(2));
	printf("1 : %d\n", ft_isdigit('8'));

	printf("\nTest de ft_isalnum :\n");
	printf("0 : %d\n", ft_isalnum(' '));
	printf("1 : %d\n", ft_isalnum('p'));
	printf("1 : %d\n", ft_isalnum('H'));
	printf("0 : %d\n", ft_isalnum(2));
	printf("1 : %d\n", ft_isalnum('8'));

	printf("\nTest de ft_isascii :\n");
	printf("1 : %d\n", ft_isascii(' '));
	printf("1 : %d\n", ft_isascii('p'));
	printf("1 : %d\n", ft_isascii(2));
	printf("0 : %d\n", ft_isascii(128));

	printf("\nTest de ft_isprint :\n");
	printf("1 : %d\n", ft_isprint(' '));
	printf("1 : %d\n", ft_isprint('p'));
	printf("0 : %d\n", ft_isprint(2));
	printf("1 : %d\n", ft_isprint(126));
	printf("0 : %d\n", ft_isprint(127));

	printf("\nTest de ft_toupper et ft_tolower :\n");
	printf("Q : %c\n", ft_toupper('Q'));
	printf("Q : %c\n", ft_toupper('q'));
	printf("q : %c\n", ft_tolower('q'));
	printf("q : %c\n", ft_tolower('Q'));

	printf("\nTest de ft_strchr :\n");
	char *str = "strinrg";
	printf("%p : %p\n", strchr(str, ' '), ft_strchr(str, ' '));
	printf("%p : %p\n", strchr(str, '\0'), ft_strchr(str, '\0'));
	printf("%p : %p\n", strchr(str, 's'), ft_strchr(str, 's'));
	printf("%p : %p\n", strchr(str, 'g'), ft_strchr(str, 'g'));

	printf("\nTest de ft_strrchr :\n");
	printf("%p : %p\n", strrchr(str, '\0'), ft_strrchr(str, '\0'));
	printf("%p : %p\n", strrchr(str, 'r'), ft_strrchr(str, 'r'));

	printf("\nTest de ft_strncmp :\n");
	printf("0 : %d\n", ft_strncmp("test", "test", 4));
	printf("-50 : %d\n", ft_strncmp("test", "test2", 5));
	printf("0 : %d\n", ft_strncmp("test", "test2", 4));
	printf("128 : %d\n", ft_strncmp("\200", "\0", 4));
	printf("1 : %d\n", ft_strncmp("tesu", "test", 6));

	printf("\nTest de ft_strlcpy :\n");
	char *c1 = "source";
	char c2[] = "destination";
	char c3[] = "destination";
	printf("6, sour : %lu, %s\n", ft_strlcpy(c2, c1, 5), c2);
	printf("6, source : %lu, %s\n", ft_strlcpy(c3, c1, 8), c3);

	printf("\nTest de ft_strlcat :\n");
	char d2[100] = "destination";
	char d3[100] = "destination";
	char d4[100] = "destination";
	char d5[100] = "dest";
	char d6[100] = "dest";
	char d7[100] = "dest";
	printf("11, destination : %lu, %s\n", ft_strlcat(d2, c1, 5), d2);
	printf("14, destination : %lu, %s\n", ft_strlcat(d3, c1, 8), d3);
	printf("17, destinations : %lu, %s\n", ft_strlcat(d4, c1, 13), d4);
	printf("10, dest : %lu, %s\n", ft_strlcat(d5, c1, 5), d5);
	printf("10, destsou: %lu, %s\n", ft_strlcat(d6, c1, 8), d6);
	printf("10, destsource : %lu, %s\n", ft_strlcat(d7, c1, 13), d7);

	printf("\nTest de ft_strnstr :\n");
	printf("ft_strnstr(\"bonjour\", \"ou\", 13) : our : %s\n", ft_strnstr("bonjour", "ou", 13));
	printf("ft_strnstr(\"bonjour\", \"njo\", 4) : (null) : %s\n", ft_strnstr("bonjour", "njo", 4));
	printf("ft_strnstr(\"bonjour\", \"njo\", 5) : njour : %s\n", ft_strnstr("bonjour", "njo", 5));

	printf("\nTest de ft_atoi :\n");
	printf("0 : %d\n", ft_atoi("0"));
	printf("1 : %d\n", ft_atoi("1"));
	printf("10 : %d\n", ft_atoi("10"));
	printf("596 : %d\n", ft_atoi("596"));
	printf("-83 : %d\n", ft_atoi("-83"));
	printf("-2147483648 : %d\n", ft_atoi("-2147483648"));
	printf("0 : %d\n", ft_atoi("---48"));
	printf("0 : %d\n", ft_atoi("-+596"));
	printf("3 : %d\n", ft_atoi(" \t +3"));
	printf("%d (long max %ld) : %d\n", atoi("9223372036854775807"), LONG_MAX, ft_atoi("9223372036854775807"));
	printf("%d (long max + 1) : %d\n", atoi("9223372036854775808"), ft_atoi("9223372036854775808"));
	printf("%d (long min %ld) : %d\n", atoi("−9223372036854775808"), LONG_MIN, ft_atoi("−9223372036854775808"));
	printf("%d (long min - 1) : %d\n", atoi("−9223372036854775809"), ft_atoi("−9223372036854775809"));

	printf("\nTest (simple compilation/free) de ft_calloc;\n");
	char *ptr;
	ptr = ft_calloc(5, sizeof(int));
	free(ptr);

	printf("\nTest de ft_strdup :\n");
	ptr = ft_strdup("string");
	printf("'string' : %s\n", ptr);
	free(ptr);

	printf("\nTest de ft_substr :\n");
	printf("njo : %s\n", ft_substr("bonjour", 2, 3));
	printf("njour : %s\n", ft_substr("bonjour", 2, 5));
	printf("njour : %s\n", ft_substr("bonjour", 2, 6));
	printf("r : %s\n", ft_substr("bonjour", 6, 1));
	printf("'' : %s\n",	ft_substr("bonjour", 6, 0));
	char stest[100] = "test";
	memset(stest + 6, 'a', 50); 
	printf("'' : %s\n",	ft_substr(stest, 10, 1));

	printf("\nTest de ft_strjoin :\n");
	printf("abcdef : %s\n",	ft_strjoin("abc", "def"));
	printf("abc : %s\n", ft_strjoin("", "abc"));
	printf("abc : %s\n", ft_strjoin("abc", ""));
	printf("'' : %s\n", ft_strjoin("", ""));

	printf("\nTest de ft_strtrim :\n");
	printf("'bonjour' : %s\n", ft_strtrim("bonjour", " "));
	printf("'bonjour' : '%s'\n", ft_strtrim(" bonjour ", " "));
	printf("'onjour' : '%s'\n", ft_strtrim(" bonjour ", " b"));
	printf("'bonjour' : '%s'\n", ft_strtrim(" bonjour", " "));
	printf("'bonjour' : '%s'\n", ft_strtrim("bonjour ", " "));
	printf("'onjou' : '%s'\n", ft_strtrim("bonjour ", "br "));
	printf("'' : '%s'\n", ft_strtrim("", " "));
	printf("'test' : '%s'\n", ft_strtrim("test", ""));
	printf("'te st' : '%s'\n", ft_strtrim(" te st ", " "));
	printf("'' : '%s'\n", ft_strtrim(" b  ", "b "));

	printf("\nTest de ft_split :\n");
	char **res;
	printf("Chaine s : 'bonjour a tous', separateur c : ' ', resultat :\n");
	res = ft_split("bonjour a tous", ' ');
	i = 0;
	while (res[i])
	{
		printf("'%s'\n", res[i]);
		i++;
	}
	printf("Chaine s : ' bonjour a tous ', separateur c : ' ', resultat :\n");
	res = ft_split(" bonjour a tous ", ' ');
	i = 0;
	while (res[i])
	{
		printf("'%s'\n", res[i]);
		i++;
	}
	printf("Chaine s : '   ', separateur c : ' ', resultat :\n");
	res = ft_split("   ", ' ');
	i = 0;
	while (res[i])
	{
		printf("'%s'\n", res[i]);
		i++;
	}
	printf("Chaine s : ' d  ', separateur c : ' ', resultat :\n");
	res = ft_split(" d  ", ' ');
	i = 0;
	while (res[i])
	{
		printf("'%s'\n", res[i]);
		i++;
	}
	printf("Chaine s : 'nosep', separateur c : ' ', resultat :\n");
	res = ft_split("nosep", ' ');
	i = 0;
	while (res[i])
	{
		printf("'%s'\n", res[i]);
		i++;
	}

	printf("\nTest de ft_itoa :\n");
	printf("0 : %s\n", ft_itoa(0));
	printf("1 : %s\n", ft_itoa(1));
	printf("-1 : %s\n", ft_itoa(-1));
	printf("234 : %s\n", ft_itoa(234));
	printf("-5689 : %s\n", ft_itoa(-5689));
	printf("2147483647 : %s\n", ft_itoa(2147483647));
	printf("-2147483648 : %s\n", ft_itoa(-2147483648));

	printf("\nTest de ft_strmapi :\n");
	printf("ABC : %s\n", ft_strmapi("abc", ft_test));

	printf("\nTest de ft_putchar_fd :\na :\n");
	ft_putchar_fd('a', 1);
	int fd = open("testputchar", O_WRONLY | O_CREAT, 0777);
	ft_putchar_fd('b', fd);
	close(fd);

	printf("\nTest de ft_putstr_fd : mot abc ci-dessous\n");
	ft_putstr_fd("abc", 1);
	fd = open("testputstr", O_WRONLY | O_CREAT, 0777);
	ft_putstr_fd("def", fd);
	close(fd);
	
	printf("\nTest de ft_putendl_fd\n");
	ft_putendl_fd("abc", 1);
	fd = open("testputendl", O_WRONLY | O_CREAT, 0777);
	ft_putendl_fd("ghi", fd);
	close(fd);

	printf("\nTest de ft_putnbr_fd :");
	printf("\n0 : \n");
	ft_putnbr_fd(0, 1);
	printf("\n1 : \n");
	ft_putnbr_fd(1, 1);
	printf("\n100 : \n");
	ft_putnbr_fd(100, 1);
	printf("\n659 : \n");
	ft_putnbr_fd(659, 1);
	printf("\n-5 : \n");
	ft_putnbr_fd(-5, 1);
	printf("\n-2147483648 : \n");
	ft_putnbr_fd(-2147483648, 1);
	fd = open("testputnbr", O_WRONLY | O_CREAT, 0777);
	ft_putnbr_fd(-593, fd);
	close(fd);
	printf("\nVerifier : 'b' dans testputchar, 'def' dans testputstr, 'ghi + nl' dans testputendl, '-593' dans testputnbr\n");

	printf("\nBONUS LISTS !\n");
	int		tab[20];
	t_list	*begin;
	*tab = 0;
	begin = ft_lstnew(tab);
	printf("Test de ft_lstnew :\n");
	if (begin && !begin->next && begin->content && *((int*)begin->content) == 0)
		printf("OK\n");
	else
		printf("Failed.\n");

	printf("\nTest de ft_lstadd_front :\n");
	i = 0;
	while (++i < 10)
	{
		tab[i] = i;
		ft_lstadd_front(&begin, ft_lstnew(tab + i));
	}
	t_list	*tmp = begin;
	printf("Should print numbers from 9 to 0.\n");
	while (tmp)
	{
		printf("%i ", *((int*)tmp->content));
		tmp = tmp->next;
	}

	printf("\n\nTest de ft_lstsize :\n");
	if (ft_lstsize(begin) == 10)
		printf("OK\n");
	else
		printf("Failed.\n");

	printf("\nTest de ft_lstlast :\n");
	if (*((int*)(ft_lstlast(begin)->content)) == 0)
		printf("OK\n");
	else
		printf("Failed.\n");

	printf("\nTest de ft_lstadd_back :\n");
	i = 0;
	while (++i < 10)
	{
		tab[i + 10] = -i;
		ft_lstadd_back(&begin, ft_lstnew(tab + i + 10));
	}
	tmp = begin;
	printf("Should print numbers from 9 to -9 :\n");
	while (tmp)
	{
		printf("%i ", *((int*)tmp->content));
		tmp = tmp->next;
	}

	printf("\n\nTest de ft_lstdelone :\n");
	tmp = begin->next;
	ft_lstdelone(begin, ft_del);
	begin = tmp;
	printf("Should print numbers from 8 to -9 :\n");
	while (tmp)
	{
		printf("%i ", *((int*)tmp->content));
		tmp = tmp->next;
	}

	printf("\n\nTest de ft_lstiter :\n");
	ft_lstiter(begin, &ft_it);

	printf("\n\nTest de ft_lstmap (+10) :\n");
	t_list		*map;
	map = ft_lstmap(begin, &ft_m, &ft_del);
	while (map)
	{
		if (begin->content)
			printf("%i ", *((int*)(map->content)));
		map = map->next;
	}

	printf("\n\nTest de ft_lstclear :\n");
	ft_lstclear(&begin, &ft_del);
	printf("Should print...nothing.\n");
	tmp = begin;
	while (tmp)
	{
		printf("%i ", *((int*)tmp->content));
		tmp = tmp->next;
	}

	printf("\n");
	return (0);
}
