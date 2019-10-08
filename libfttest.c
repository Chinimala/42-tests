/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 10:36:16 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/08 16:57:32 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include "test.h"

char	ft_test(unsigned int i, char c)
{
	i = 0;
	return (c - 32);
}

int		main(void)
{
	char s[100] = "aaaaa";
	printf("Test de ft_memset(s, 'z', 3) avec s = 'aaaaa' : %s\n",
	ft_memset(s, 'z', 3));

	ft_bzero(s, 3);
	printf("\nTest de ft_bzero(s, 3) : [%c][%c][%c][%c][%c]\n", s[0], s[1], s[2], s[3], s[4]);

	printf("\nTest de ft_memcpy(s, \"source\", 3) : %s\n",
	ft_memcpy(s, "source", 3));
	printf("Test de ft_memcpy(s, \"2emesource\", 8) : %s\n",
	ft_memcpy(s, "2emesource", 8));

	printf("\nTest de ft_memccpy : \n");
	char dst[100] = "destination";
	printf("memccpy : %p %s\n", memccpy(dst, "source", ' ', 8), dst);
	char dst2[100] = "destination";
	printf("ft_memccpy : %p %s\n", ft_memccpy(dst2, "source", ' ', 8), dst2);
	printf("memccpy : %p %s\n", memccpy(dst, "2emesource", 'e', 8), dst);
	printf("ft_memccpy : %p %s\n", ft_memccpy(dst, "2emesource", 'e', 8), dst);

	printf("\nTest de ft_memmove : \n");
	char s1[] = "string test";
	memmove(s1, s1 + 3, 5);
	printf("memmove : %s\n", s1);
	char s2[] = "string test";
	ft_memmove(s2, s2 + 3, 5);
	printf("ft_memmove : %s\n", s2);
	memmove(s1 + 3, s1, 5);
	printf("memmove : %s\n", s1);
	ft_memmove(s2 + 3, s2, 5);
	printf("ft_memmove : %s\n", s2);

	printf("\nTest de ft_memchr : \n");
	printf("ft_memchr(\"source\", 'r', 2) : %s\n", ft_memchr("source", 'r', 2));
	printf("ft_memchr(\"source\", 'r', 5) : %s\n", ft_memchr("source", 'r', 5));

	printf("\nTest de ft_memcmp : \n");
	printf("0 : %d\n", ft_memcmp("test", "test", 4));
	printf("-50 : %d\n", ft_memcmp("test", "test2", 5));
	printf("0 : %d\n", ft_memcmp("test", "test2", 4));
	printf("128 : %d\n", ft_memcmp("\200", "\0", 4));
	printf("1 : %d\n", ft_memcmp("tesu", "test", 6));

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
	printf("P : %c\n", ft_toupper('P'));
	printf("P : %c\n", ft_toupper('p'));
	printf("p : %c\n", ft_tolower('p'));
	printf("p : %c\n", ft_tolower('P'));

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

	printf("\nTest de ft_substr :\n");
	printf("Chaine s : bonjour; start : 2; len : 3; resultat : %s\n",
	ft_substr("bonjour", 2, 3));
	printf("Chaine s : bonjour; start : 2; len : 5; resultat : %s\n",
	ft_substr("bonjour", 2, 5));
	printf("Chaine s : bonjour; start : 2; len : 6; resultat : %s\n",
	ft_substr("bonjour", 2, 6));
	printf("Chaine s : bonjour; start : 6; len : 1; resultat : %s\n",
	ft_substr("bonjour", 6, 1));
	printf("Chaine s : bonjour; start : 6; len : 0; resultat : %s\n",
	ft_substr("bonjour", 6, 0));

	printf("\nTest de ft_strjoin :\n");
	printf("Chaine s1 : abc; chaine s2 : def; resultat : %s\n",
	ft_strjoin("abc", "def"));
	printf("Chaine s1 : \"\"; chaine s2 : abc; resultat : %s\n",
	ft_strjoin("", "abc"));
	printf("Chaine s1 : abc; chaine s2 : \"\"; resultat : %s\n",
	ft_strjoin("abc", ""));
	printf("Chaine s1 : \"\"; chaine s2 : \"\"; resultat : %s\n",
	ft_strjoin("", ""));

	printf("\nTest de ft_strtrim :\n");
	printf("Chaine s1 : 'bonjour', set : ' ', resultat : '%s'\n",
	ft_strtrim("bonjour", " "));
	printf("Chaine s1 : ' bonjour ', set : ' ', resultat : '%s'\n",
	ft_strtrim(" bonjour ", " "));
	printf("Chaine s1 : ' bonjour ', set : ' b', resultat : '%s'\n",
	ft_strtrim(" bonjour ", " b"));
	printf("Chaine s1 : ' bonjour', set : ' ', resultat : '%s'\n",
	ft_strtrim(" bonjour", " "));
	printf("Chaine s1 : 'bonjour ', set : ' ', resultat : '%s'\n",
	ft_strtrim("bonjour ", " "));
	printf("Chaine s1 : 'bonjour ', set : 'br ', resultat : '%s'\n",
	ft_strtrim("bonjour ", "br "));
	printf("Chaine s1 : '', set : ' ', resultat : '%s'\n",
	ft_strtrim("", " "));
	printf("Chaine s1 : 'test', set : '', resultat : '%s'\n",
	ft_strtrim("test", ""));
	printf("Chaine s1 : ' te  st ', set : ' ', resultat : '%s'\n",
	ft_strtrim(" te st ", " "));
	printf("Chaine s1 : ' b  ', set : 'b ', resultat : '%s'\n",
	ft_strtrim(" b  ", "b "));

	printf("\nTest de ft_split :\n");
	char **res;
	int i;
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
	printf("abc en capitales : %s\n", ft_strmapi("abc", ft_test));

	printf("\nTest de ft_putchar_fd : lettre a ci-dessous\n");
	ft_putchar_fd('a', 1);
	printf("\nTest de ft_putchar_fd : lettre b dans fichier testputchar\n");
	int fd = open("testputchar", O_WRONLY | O_CREAT, 0777);
	ft_putchar_fd('b', fd);
	close(fd);

	printf("\nTest de ft_putstr_fd : mot abc ci-dessous\n");
	ft_putstr_fd("abc", 1);
	printf("\nTest de ft_putstr_fd : mot def dans fichier testputstr\n");
	fd = open("testputstr", O_WRONLY | O_CREAT, 0777);
	ft_putstr_fd("def", fd);
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
	printf("\nTest de ft_putnbr_fd : -593 dans fichier testputnbr\n");
	fd = open("testputnbr", O_WRONLY | O_CREAT, 0777);
	ft_putnbr_fd(-593, fd);
	close(fd);
	return (0);
}
