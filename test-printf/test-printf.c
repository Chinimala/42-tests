/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/07 17:19:51 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>
#include <locale.h>

int		ft_printf(const char *s, ...);

int		main(int ac, char **av)
{
	int		nb;
	int		count;

	nb = atoi(av[1]);
	count = 0;


	// [A - Tests without options].
	if (nb == count++)
		return(ac == 2 ? printf("") : ft_printf(""));
	if (nb == count++)
		return(ac == 2 ? printf("1") : ft_printf("1"));
	if (nb == count++)
		return(ac == 2 ? printf("%%") : ft_printf("%%"));
	if (nb == count++)
		return(ac == 2 ? printf("%%%%") : ft_printf("%%%%"));
	if (nb == count++)
		return(ac == 2 ? printf("%%%%%%") : ft_printf("%%%%%%"));
	if (nb == count++)
		return(ac == 2 ? printf("%c", '1') : ft_printf("%c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%c", -207) : ft_printf("%c", -207));
	if (nb == count++)
		return(ac == 2 ? printf("%c", 256 + 48) : ft_printf("%c", 256 + 48));
	if (nb == count++)
		return(ac == 2 ? printf("%c%%", '3') : ft_printf("%c%%", '3'));
	if (nb == count++)
		return(ac == 2 ? printf("0%c", 0) : ft_printf("0%c", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%c", -129) : ft_printf("%c", -129));
	if (nb == count++)
		return(ac == 2 ? printf("%c", 128) : ft_printf("%c", 128));
	if (nb == count++)
		return(ac == 2 ? printf("%c", 0) : ft_printf("%c", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%s", "Hello") : ft_printf("%s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%s%%", "Hello3") : ft_printf("%s%%", "Hello3"));
	if (nb == count++)
		return(ac == 2 ? printf("%s", "") : ft_printf("%s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%s", "1") : ft_printf("%s", "1"));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 0) : ft_printf("%i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%i", -1) : ft_printf("%i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%i", -42) : ft_printf("%i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 1) : ft_printf("%i", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 42) : ft_printf("%i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%i", INT_MAX) : ft_printf("%i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%i", INT_MAX + 1) : ft_printf("%i", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%i", INT_MIN) : ft_printf("%i", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%i", 1000) : ft_printf("%i", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%i", -1000) : ft_printf("%i", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 0) : ft_printf("%d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%d", -1) : ft_printf("%d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%d", -42) : ft_printf("%d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 1) : ft_printf("%d", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 42) : ft_printf("%d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%d", INT_MAX) : ft_printf("%d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%d", INT_MAX + 1) : ft_printf("%d", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%d", INT_MIN) : ft_printf("%d", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%d", 1000) : ft_printf("%d", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%d", -1000) : ft_printf("%d", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 0) : ft_printf("%u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%u", -1) : ft_printf("%u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 1) : ft_printf("%u", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 42) : ft_printf("%u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%u", UINT_MAX) : ft_printf("%u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%u", UINT_MAX + 1) : ft_printf("%u", UINT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%u", 1000) : ft_printf("%u", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 0) : ft_printf("%x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%x", -1) : ft_printf("%x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%x", -42) : ft_printf("%x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 1) : ft_printf("%x", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 42) : ft_printf("%x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%x", INT_MAX) : ft_printf("%x", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%x", INT_MAX + 1) : ft_printf("%x", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%x", INT_MIN) : ft_printf("%x", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%x", 1000) : ft_printf("%x", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%x", -1000) : ft_printf("%x", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 0) : ft_printf("%X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%X", -1) : ft_printf("%X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%X", -42) : ft_printf("%X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 1) : ft_printf("%X", 1));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 42) : ft_printf("%X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%X", INT_MAX) : ft_printf("%X", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%X", INT_MAX + 1) : ft_printf("%X", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%X", INT_MIN) : ft_printf("%X", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%X", 1000) : ft_printf("%X", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%X", -1000) : ft_printf("%X", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)1) : ft_printf("%p", (void*)1));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)-1) : ft_printf("%p", (void*)-1));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)42) : ft_printf("%p", (void*)42));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)1000) : ft_printf("%p", (void*)1000));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)ULONG_MAX) : ft_printf("%p", (void*)ULONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%p", (void*)ULONG_MAX + 1) : ft_printf("%p", (void*)ULONG_MAX + 1));

	// [B - Tests with minimum field width].
	if (nb == count++)
		return(ac == 2 ? printf("%*c", -1000, 'a') : ft_printf("%*c", -1000, 'a'));
	if (nb == count++)
		return(ac == 2 ? printf("%*s", -1000, "") : ft_printf("%*s", -1000, ""));
	if (nb == count++)
		return(ac == 2 ? printf("%1%") : ft_printf("%1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%2%") : ft_printf("%2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%10%") : ft_printf("%10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%1c", '1') : ft_printf("%1c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%2c", '1') : ft_printf("%2c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%10c", '1') : ft_printf("%10c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%1s", "") : ft_printf("%1s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%5s", "Hello") : ft_printf("%5s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%6s", "Hello") : ft_printf("%6s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%1i", 0) : ft_printf("%1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2i", 0) : ft_printf("%2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10i", 0) : ft_printf("%10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1i", -1) : ft_printf("%1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2i", -1) : ft_printf("%2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3i", -1) : ft_printf("%3i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9i", INT_MAX) : ft_printf("%9i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10i", INT_MAX) : ft_printf("%10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11i", INT_MAX) : ft_printf("%11i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1d", 0) : ft_printf("%1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2d", 0) : ft_printf("%2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10d", 0) : ft_printf("%10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1d", -1) : ft_printf("%1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2d", -1) : ft_printf("%2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3d", -1) : ft_printf("%3d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9d", INT_MAX) : ft_printf("%9d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10d", INT_MAX) : ft_printf("%10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11d", INT_MAX) : ft_printf("%11d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1u", 0) : ft_printf("%1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2u", 0) : ft_printf("%2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10u", 0) : ft_printf("%10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1u", -1) : ft_printf("%1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2u", -1) : ft_printf("%2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3u", -1) : ft_printf("%3u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9u", UINT_MAX) : ft_printf("%9u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10u", UINT_MAX) : ft_printf("%10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11u", UINT_MAX) : ft_printf("%11u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1x", 0) : ft_printf("%1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2x", 0) : ft_printf("%2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10x", 0) : ft_printf("%10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1x", -1) : ft_printf("%1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2x", -1) : ft_printf("%2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3x", -1) : ft_printf("%3x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9x", UINT_MAX) : ft_printf("%9x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10x", UINT_MAX) : ft_printf("%10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11x", UINT_MAX) : ft_printf("%11x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1X", 0) : ft_printf("%1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2X", 0) : ft_printf("%2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10X", 0) : ft_printf("%10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1X", -1) : ft_printf("%1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2X", -1) : ft_printf("%2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3X", -1) : ft_printf("%3X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9X", UINT_MAX) : ft_printf("%9X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10X", UINT_MAX) : ft_printf("%10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11X", UINT_MAX) : ft_printf("%11X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1p", (void*)42) : ft_printf("%1p", (void*)42));
	if (nb == count++)
		return(ac == 2 ? printf("%5p", (void*)42) : ft_printf("%5p", (void*)42));

	// [C - Tests with flag -].
	if (nb == count++)
		return(ac == 2 ? printf("%-1%") : ft_printf("%-1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2%") : ft_printf("%-2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10%") : ft_printf("%-10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1c", '1') : ft_printf("%-1c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%-2c", '1') : ft_printf("%-2c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%-10c", '1') : ft_printf("%-10c", '1'));
	if (nb == count++)
		return(ac == 2 ? printf("%-1s", "") : ft_printf("%-1s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-5s", "Hello") : ft_printf("%-5s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6s", "Hello") : ft_printf("%-6s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1i", 0) : ft_printf("%-1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2i", 0) : ft_printf("%-2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10i", 0) : ft_printf("%-10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1i", -1) : ft_printf("%-1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2i", -1) : ft_printf("%-2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3i", -1) : ft_printf("%-3i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9i", INT_MAX) : ft_printf("%-9i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10i", INT_MAX) : ft_printf("%-10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11i", INT_MAX) : ft_printf("%-11i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1d", 0) : ft_printf("%-1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2d", 0) : ft_printf("%-2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10d", 0) : ft_printf("%-10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1d", -1) : ft_printf("%-1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2d", -1) : ft_printf("%-2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3d", -1) : ft_printf("%-3d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9d", INT_MAX) : ft_printf("%-9d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10d", INT_MAX) : ft_printf("%-10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11d", INT_MAX) : ft_printf("%-11d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1u", 0) : ft_printf("%-1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2u", 0) : ft_printf("%-2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10u", 0) : ft_printf("%-10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1u", -1) : ft_printf("%-1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2u", -1) : ft_printf("%-2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3u", -1) : ft_printf("%-3u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9u", UINT_MAX) : ft_printf("%-9u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10u", UINT_MAX) : ft_printf("%-10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11u", UINT_MAX) : ft_printf("%-11u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1x", 0) : ft_printf("%-1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2x", 0) : ft_printf("%-2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10x", 0) : ft_printf("%-10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1x", -1) : ft_printf("%-1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2x", -1) : ft_printf("%-2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3x", -1) : ft_printf("%-3x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9x", UINT_MAX) : ft_printf("%-9x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10x", UINT_MAX) : ft_printf("%-10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11x", UINT_MAX) : ft_printf("%-11x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1X", 0) : ft_printf("%-1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2X", 0) : ft_printf("%-2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10X", 0) : ft_printf("%-10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1X", -1) : ft_printf("%-1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2X", -1) : ft_printf("%-2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3X", -1) : ft_printf("%-3X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9X", UINT_MAX) : ft_printf("%-9X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10X", UINT_MAX) : ft_printf("%-10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11X", UINT_MAX) : ft_printf("%-11X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1p", (void*)42) : ft_printf("%-1p", (void*)42));
	if (nb == count++)
		return(ac == 2 ? printf("%-5p", (void*)42) : ft_printf("%-5p", (void*)42));

	// [D - Tests with flag 0].
	if (nb == count++)
		return(ac == 2 ? printf("%01i", 0) : ft_printf("%01i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02i", 0) : ft_printf("%02i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010i", 0) : ft_printf("%010i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01i", -1) : ft_printf("%01i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02i", -1) : ft_printf("%02i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03i", -1) : ft_printf("%03i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09i", INT_MAX) : ft_printf("%09i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010i", INT_MAX) : ft_printf("%010i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011i", INT_MAX) : ft_printf("%011i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01d", 0) : ft_printf("%01d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02d", 0) : ft_printf("%02d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010d", 0) : ft_printf("%010d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01d", -1) : ft_printf("%01d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02d", -1) : ft_printf("%02d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03d", -1) : ft_printf("%03d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09d", INT_MAX) : ft_printf("%09d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010d", INT_MAX) : ft_printf("%010d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011d", INT_MAX) : ft_printf("%011d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01u", 0) : ft_printf("%01u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02u", 0) : ft_printf("%02u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010u", 0) : ft_printf("%010u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01u", -1) : ft_printf("%01u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02u", -1) : ft_printf("%02u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03u", -1) : ft_printf("%03u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09u", UINT_MAX) : ft_printf("%09u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010u", UINT_MAX) : ft_printf("%010u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011u", UINT_MAX) : ft_printf("%011u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01x", 0) : ft_printf("%01x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02x", 0) : ft_printf("%02x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010x", 0) : ft_printf("%010x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01x", -1) : ft_printf("%01x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02x", -1) : ft_printf("%02x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03x", -1) : ft_printf("%03x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09x", UINT_MAX) : ft_printf("%09x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010x", UINT_MAX) : ft_printf("%010x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011x", UINT_MAX) : ft_printf("%011x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01X", 0) : ft_printf("%01X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02X", 0) : ft_printf("%02X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010X", 0) : ft_printf("%010X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01X", -1) : ft_printf("%01X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02X", -1) : ft_printf("%02X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03X", -1) : ft_printf("%03X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09X", UINT_MAX) : ft_printf("%09X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010X", UINT_MAX) : ft_printf("%010X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011X", UINT_MAX) : ft_printf("%011X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%0-10d", 42) : ft_printf("%0-10d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%-010d", 42) : ft_printf("%-010d", 42));

	// [E - Tests with .].
	if (nb == count++)
		return(ac == 2 ? printf("%.0%") : ft_printf("%.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.0%") : ft_printf("%.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.1%") : ft_printf("%.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.2%") : ft_printf("%.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.10%") : ft_printf("%.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%.0s", "") : ft_printf("%.0s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%.1s", "") : ft_printf("%.1s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%.3s", "") : ft_printf("%.3s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%.0s", "Hello") : ft_printf("%.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.1s", "Hello") : ft_printf("%.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.2s", "Hello") : ft_printf("%.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.5s", "Hello") : ft_printf("%.5s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.6s", "Hello") : ft_printf("%.6s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.7s", "Hello") : ft_printf("%.7s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%.s", 42) : ft_printf("%.s", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", 0) : ft_printf("%.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", 0) : ft_printf("%.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", 0) : ft_printf("%.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", 5) : ft_printf("%.0d", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", 5) : ft_printf("%.1d", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", 5) : ft_printf("%.2d", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", 42) : ft_printf("%.0d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", 42) : ft_printf("%.1d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", 42) : ft_printf("%.2d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3d", 42) : ft_printf("%.3d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10d", 42) : ft_printf("%.10d", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6d", 100) : ft_printf("%.6d", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", -1) : ft_printf("%.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", -1) : ft_printf("%.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2d", -1) : ft_printf("%.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3d", -1) : ft_printf("%.3d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0d", -42) : ft_printf("%.0d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1d", -42) : ft_printf("%.1d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3d", -42) : ft_printf("%.3d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4d", -42) : ft_printf("%.4d", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MAX) : ft_printf("%.20d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MAX + 1) : ft_printf("%.20d", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MIN) : ft_printf("%.20d", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%.20d", INT_MIN - 1) : ft_printf("%.20d", INT_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", 0) : ft_printf("%.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", 0) : ft_printf("%.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", 0) : ft_printf("%.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", 5) : ft_printf("%.0i", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", 5) : ft_printf("%.1i", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", 5) : ft_printf("%.2i", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", 42) : ft_printf("%.0i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", 42) : ft_printf("%.1i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", 42) : ft_printf("%.2i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3i", 42) : ft_printf("%.3i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10i", 42) : ft_printf("%.10i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6i", 100) : ft_printf("%.6i", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", -1) : ft_printf("%.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", -1) : ft_printf("%.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2i", -1) : ft_printf("%.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3i", -1) : ft_printf("%.3i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0i", -42) : ft_printf("%.0i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1i", -42) : ft_printf("%.1i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3i", -42) : ft_printf("%.3i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4i", -42) : ft_printf("%.4i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MAX) : ft_printf("%.20i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MAX + 1) : ft_printf("%.20i", INT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MIN) : ft_printf("%.20i", INT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%.20i", INT_MIN - 1) : ft_printf("%.20i", INT_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", 0) : ft_printf("%.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", 0) : ft_printf("%.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", 0) : ft_printf("%.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", 5) : ft_printf("%.0u", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", 5) : ft_printf("%.1u", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", 5) : ft_printf("%.2u", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", 42) : ft_printf("%.0u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", 42) : ft_printf("%.1u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", 42) : ft_printf("%.2u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3u", 42) : ft_printf("%.3u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10u", 42) : ft_printf("%.10u", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6u", 100) : ft_printf("%.6u", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", -1) : ft_printf("%.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", -1) : ft_printf("%.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2u", -1) : ft_printf("%.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3u", -1) : ft_printf("%.3u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0u", -42) : ft_printf("%.0u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1u", -42) : ft_printf("%.1u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3u", -42) : ft_printf("%.3u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4u", -42) : ft_printf("%.4u", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20u", UINT_MAX) : ft_printf("%.20u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20u", UINT_MAX + 1) : ft_printf("%.20u", UINT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", 0) : ft_printf("%.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", 0) : ft_printf("%.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", 0) : ft_printf("%.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", 5) : ft_printf("%.0x", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", 5) : ft_printf("%.1x", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", 5) : ft_printf("%.2x", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", 42) : ft_printf("%.0x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", 42) : ft_printf("%.1x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", 42) : ft_printf("%.2x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3x", 42) : ft_printf("%.3x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10x", 42) : ft_printf("%.10x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6x", 100) : ft_printf("%.6x", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", -1) : ft_printf("%.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", -1) : ft_printf("%.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2x", -1) : ft_printf("%.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3x", -1) : ft_printf("%.3x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0x", -42) : ft_printf("%.0x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1x", -42) : ft_printf("%.1x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3x", -42) : ft_printf("%.3x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4x", -42) : ft_printf("%.4x", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20x", UINT_MAX) : ft_printf("%.20x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20x", UINT_MAX + 1) : ft_printf("%.20x", UINT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", 0) : ft_printf("%.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", 0) : ft_printf("%.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", 0) : ft_printf("%.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", 5) : ft_printf("%.0X", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", 5) : ft_printf("%.1X", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", 5) : ft_printf("%.2X", 5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", 42) : ft_printf("%.0X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", 42) : ft_printf("%.1X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", 42) : ft_printf("%.2X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3X", 42) : ft_printf("%.3X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.10X", 42) : ft_printf("%.10X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.6X", 100) : ft_printf("%.6X", 100));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", -1) : ft_printf("%.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", -1) : ft_printf("%.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2X", -1) : ft_printf("%.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3X", -1) : ft_printf("%.3X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0X", -42) : ft_printf("%.0X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1X", -42) : ft_printf("%.1X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3X", -42) : ft_printf("%.3X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.4X", -42) : ft_printf("%.4X", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.20X", UINT_MAX) : ft_printf("%.20X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%.20X", UINT_MAX + 1) : ft_printf("%.20X", UINT_MAX + 1));

	// [F - Tests with minimum field width and .].
	if (nb == count++)
		return(ac == 2 ? printf("%1.0%") : ft_printf("%1.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1%") : ft_printf("%1.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2%") : ft_printf("%1.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10%") : ft_printf("%1.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0%") : ft_printf("%2.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1%") : ft_printf("%2.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2%") : ft_printf("%2.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10%") : ft_printf("%2.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0%") : ft_printf("%10.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1%") : ft_printf("%10.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2%") : ft_printf("%10.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10%") : ft_printf("%10.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0s", "") : ft_printf("%1.0s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1s", "") : ft_printf("%1.1s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2s", "") : ft_printf("%1.2s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10s", "") : ft_printf("%1.10s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%5.0s", "Hello") : ft_printf("%5.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%5.1s", "Hello") : ft_printf("%5.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%5.2s", "Hello") : ft_printf("%5.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%5.10s", "Hello") : ft_printf("%5.10s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%6.0s", "Hello") : ft_printf("%6.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%6.1s", "Hello") : ft_printf("%6.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%6.2s", "Hello") : ft_printf("%6.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%6.10s", "Hello") : ft_printf("%6.10s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0i", 0) : ft_printf("%1.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1i", 0) : ft_printf("%1.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2i", 0) : ft_printf("%1.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10i", 0) : ft_printf("%1.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0i", 0) : ft_printf("%2.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1i", 0) : ft_printf("%2.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2i", 0) : ft_printf("%2.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10i", 0) : ft_printf("%2.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0i", 0) : ft_printf("%10.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1i", 0) : ft_printf("%10.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2i", 0) : ft_printf("%10.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10i", 0) : ft_printf("%10.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0i", -1) : ft_printf("%1.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1i", -1) : ft_printf("%1.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2i", -1) : ft_printf("%1.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10i", -1) : ft_printf("%1.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0i", -1) : ft_printf("%2.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1i", -1) : ft_printf("%2.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2i", -1) : ft_printf("%2.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10i", -1) : ft_printf("%2.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.0i", -1) : ft_printf("%3.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.1i", -1) : ft_printf("%3.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.2i", -1) : ft_printf("%3.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.10i", -1) : ft_printf("%3.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9.0i", INT_MAX) : ft_printf("%9.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.1i", INT_MAX) : ft_printf("%9.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.2i", INT_MAX) : ft_printf("%9.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.10i", INT_MAX) : ft_printf("%9.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0i", INT_MAX) : ft_printf("%10.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1i", INT_MAX) : ft_printf("%10.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2i", INT_MAX) : ft_printf("%10.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10i", INT_MAX) : ft_printf("%10.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.0i", INT_MAX) : ft_printf("%11.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.1i", INT_MAX) : ft_printf("%11.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.2i", INT_MAX) : ft_printf("%11.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.10i", INT_MAX) : ft_printf("%11.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0d", 0) : ft_printf("%1.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1d", 0) : ft_printf("%1.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2d", 0) : ft_printf("%1.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10d", 0) : ft_printf("%1.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0d", 0) : ft_printf("%2.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1d", 0) : ft_printf("%2.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2d", 0) : ft_printf("%2.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10d", 0) : ft_printf("%2.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0d", 0) : ft_printf("%10.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1d", 0) : ft_printf("%10.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2d", 0) : ft_printf("%10.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10d", 0) : ft_printf("%10.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0d", -1) : ft_printf("%1.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1d", -1) : ft_printf("%1.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2d", -1) : ft_printf("%1.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10d", -1) : ft_printf("%1.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0d", -1) : ft_printf("%2.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1d", -1) : ft_printf("%2.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2d", -1) : ft_printf("%2.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10d", -1) : ft_printf("%2.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.0d", -1) : ft_printf("%3.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.1d", -1) : ft_printf("%3.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.2d", -1) : ft_printf("%3.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.10d", -1) : ft_printf("%3.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9.0d", INT_MAX) : ft_printf("%9.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.1d", INT_MAX) : ft_printf("%9.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.2d", INT_MAX) : ft_printf("%9.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.10d", INT_MAX) : ft_printf("%9.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0d", INT_MAX) : ft_printf("%10.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1d", INT_MAX) : ft_printf("%10.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2d", INT_MAX) : ft_printf("%10.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10d", INT_MAX) : ft_printf("%10.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.0d", INT_MAX) : ft_printf("%11.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.1d", INT_MAX) : ft_printf("%11.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.2d", INT_MAX) : ft_printf("%11.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.10d", INT_MAX) : ft_printf("%11.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0u", 0) : ft_printf("%1.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1u", 0) : ft_printf("%1.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2u", 0) : ft_printf("%1.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10u", 0) : ft_printf("%1.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0u", 0) : ft_printf("%2.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1u", 0) : ft_printf("%2.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2u", 0) : ft_printf("%2.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10u", 0) : ft_printf("%2.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0u", 0) : ft_printf("%10.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1u", 0) : ft_printf("%10.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2u", 0) : ft_printf("%10.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10u", 0) : ft_printf("%10.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0u", -1) : ft_printf("%1.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1u", -1) : ft_printf("%1.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2u", -1) : ft_printf("%1.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10u", -1) : ft_printf("%1.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0u", -1) : ft_printf("%2.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1u", -1) : ft_printf("%2.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2u", -1) : ft_printf("%2.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10u", -1) : ft_printf("%2.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.0u", -1) : ft_printf("%3.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.1u", -1) : ft_printf("%3.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.2u", -1) : ft_printf("%3.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.10u", -1) : ft_printf("%3.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9.0u", UINT_MAX) : ft_printf("%9.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.1u", UINT_MAX) : ft_printf("%9.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.2u", UINT_MAX) : ft_printf("%9.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.10u", UINT_MAX) : ft_printf("%9.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0u", UINT_MAX) : ft_printf("%10.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1u", UINT_MAX) : ft_printf("%10.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2u", UINT_MAX) : ft_printf("%10.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10u", UINT_MAX) : ft_printf("%10.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.0u", UINT_MAX) : ft_printf("%11.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.1u", UINT_MAX) : ft_printf("%11.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.2u", UINT_MAX) : ft_printf("%11.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.10u", UINT_MAX) : ft_printf("%11.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0x", 0) : ft_printf("%1.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1x", 0) : ft_printf("%1.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2x", 0) : ft_printf("%1.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10x", 0) : ft_printf("%1.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0x", 0) : ft_printf("%2.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1x", 0) : ft_printf("%2.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2x", 0) : ft_printf("%2.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10x", 0) : ft_printf("%2.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0x", 0) : ft_printf("%10.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1x", 0) : ft_printf("%10.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2x", 0) : ft_printf("%10.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10x", 0) : ft_printf("%10.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0x", -1) : ft_printf("%1.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1x", -1) : ft_printf("%1.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2x", -1) : ft_printf("%1.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10x", -1) : ft_printf("%1.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0x", -1) : ft_printf("%2.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1x", -1) : ft_printf("%2.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2x", -1) : ft_printf("%2.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10x", -1) : ft_printf("%2.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.0x", -1) : ft_printf("%3.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.1x", -1) : ft_printf("%3.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.2x", -1) : ft_printf("%3.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.10x", -1) : ft_printf("%3.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9.0x", UINT_MAX) : ft_printf("%9.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.1x", UINT_MAX) : ft_printf("%9.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.2x", UINT_MAX) : ft_printf("%9.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.10x", UINT_MAX) : ft_printf("%9.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0x", UINT_MAX) : ft_printf("%10.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1x", UINT_MAX) : ft_printf("%10.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2x", UINT_MAX) : ft_printf("%10.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10x", UINT_MAX) : ft_printf("%10.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.0x", UINT_MAX) : ft_printf("%11.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.1x", UINT_MAX) : ft_printf("%11.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.2x", UINT_MAX) : ft_printf("%11.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.10x", UINT_MAX) : ft_printf("%11.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0X", 0) : ft_printf("%1.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1X", 0) : ft_printf("%1.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2X", 0) : ft_printf("%1.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10X", 0) : ft_printf("%1.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0X", 0) : ft_printf("%2.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1X", 0) : ft_printf("%2.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2X", 0) : ft_printf("%2.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10X", 0) : ft_printf("%2.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0X", 0) : ft_printf("%10.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1X", 0) : ft_printf("%10.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2X", 0) : ft_printf("%10.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10X", 0) : ft_printf("%10.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%1.0X", -1) : ft_printf("%1.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.1X", -1) : ft_printf("%1.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.2X", -1) : ft_printf("%1.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%1.10X", -1) : ft_printf("%1.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.0X", -1) : ft_printf("%2.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.1X", -1) : ft_printf("%2.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.2X", -1) : ft_printf("%2.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%2.10X", -1) : ft_printf("%2.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.0X", -1) : ft_printf("%3.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.1X", -1) : ft_printf("%3.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.2X", -1) : ft_printf("%3.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%3.10X", -1) : ft_printf("%3.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%9.0X", UINT_MAX) : ft_printf("%9.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.1X", UINT_MAX) : ft_printf("%9.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.2X", UINT_MAX) : ft_printf("%9.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%9.10X", UINT_MAX) : ft_printf("%9.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.0X", UINT_MAX) : ft_printf("%10.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.1X", UINT_MAX) : ft_printf("%10.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.2X", UINT_MAX) : ft_printf("%10.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%10.10X", UINT_MAX) : ft_printf("%10.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.0X", UINT_MAX) : ft_printf("%11.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.1X", UINT_MAX) : ft_printf("%11.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.2X", UINT_MAX) : ft_printf("%11.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%11.10X", UINT_MAX) : ft_printf("%11.10X", UINT_MAX));

	// [G - Tests with minimum field width, flag - and .].
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0%") : ft_printf("%-1.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1%") : ft_printf("%-1.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2%") : ft_printf("%-1.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10%") : ft_printf("%-1.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0%") : ft_printf("%-2.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1%") : ft_printf("%-2.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2%") : ft_printf("%-2.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10%") : ft_printf("%-2.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0%") : ft_printf("%-10.0%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1%") : ft_printf("%-10.1%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2%") : ft_printf("%-10.2%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10%") : ft_printf("%-10.10%"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0s", "") : ft_printf("%-1.0s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1s", "") : ft_printf("%-1.1s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2s", "") : ft_printf("%-1.2s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10s", "") : ft_printf("%-1.10s", ""));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.0s", "Hello") : ft_printf("%-5.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.1s", "Hello") : ft_printf("%-5.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.2s", "Hello") : ft_printf("%-5.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-5.10s", "Hello") : ft_printf("%-5.10s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.0s", "Hello") : ft_printf("%-6.0s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.1s", "Hello") : ft_printf("%-6.1s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.2s", "Hello") : ft_printf("%-6.2s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-6.10s", "Hello") : ft_printf("%-6.10s", "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0i", 0) : ft_printf("%-1.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1i", 0) : ft_printf("%-1.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2i", 0) : ft_printf("%-1.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10i", 0) : ft_printf("%-1.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0i", 0) : ft_printf("%-2.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1i", 0) : ft_printf("%-2.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2i", 0) : ft_printf("%-2.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10i", 0) : ft_printf("%-2.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0i", 0) : ft_printf("%-10.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1i", 0) : ft_printf("%-10.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2i", 0) : ft_printf("%-10.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10i", 0) : ft_printf("%-10.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0i", -1) : ft_printf("%-1.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1i", -1) : ft_printf("%-1.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2i", -1) : ft_printf("%-1.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10i", -1) : ft_printf("%-1.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0i", -1) : ft_printf("%-2.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1i", -1) : ft_printf("%-2.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2i", -1) : ft_printf("%-2.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10i", -1) : ft_printf("%-2.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0i", -1) : ft_printf("%-3.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1i", -1) : ft_printf("%-3.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2i", -1) : ft_printf("%-3.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10i", -1) : ft_printf("%-3.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0i", INT_MAX) : ft_printf("%-9.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1i", INT_MAX) : ft_printf("%-9.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2i", INT_MAX) : ft_printf("%-9.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10i", INT_MAX) : ft_printf("%-9.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0i", INT_MAX) : ft_printf("%-10.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1i", INT_MAX) : ft_printf("%-10.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2i", INT_MAX) : ft_printf("%-10.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10i", INT_MAX) : ft_printf("%-10.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0i", INT_MAX) : ft_printf("%-11.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1i", INT_MAX) : ft_printf("%-11.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2i", INT_MAX) : ft_printf("%-11.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10i", INT_MAX) : ft_printf("%-11.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0d", 0) : ft_printf("%-1.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1d", 0) : ft_printf("%-1.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2d", 0) : ft_printf("%-1.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10d", 0) : ft_printf("%-1.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0d", 0) : ft_printf("%-2.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1d", 0) : ft_printf("%-2.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2d", 0) : ft_printf("%-2.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10d", 0) : ft_printf("%-2.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0d", 0) : ft_printf("%-10.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1d", 0) : ft_printf("%-10.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2d", 0) : ft_printf("%-10.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10d", 0) : ft_printf("%-10.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0d", -1) : ft_printf("%-1.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1d", -1) : ft_printf("%-1.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2d", -1) : ft_printf("%-1.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10d", -1) : ft_printf("%-1.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0d", -1) : ft_printf("%-2.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1d", -1) : ft_printf("%-2.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2d", -1) : ft_printf("%-2.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10d", -1) : ft_printf("%-2.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0d", -1) : ft_printf("%-3.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1d", -1) : ft_printf("%-3.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2d", -1) : ft_printf("%-3.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10d", -1) : ft_printf("%-3.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0d", INT_MAX) : ft_printf("%-9.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1d", INT_MAX) : ft_printf("%-9.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2d", INT_MAX) : ft_printf("%-9.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10d", INT_MAX) : ft_printf("%-9.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0d", INT_MAX) : ft_printf("%-10.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1d", INT_MAX) : ft_printf("%-10.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2d", INT_MAX) : ft_printf("%-10.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10d", INT_MAX) : ft_printf("%-10.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0d", INT_MAX) : ft_printf("%-11.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1d", INT_MAX) : ft_printf("%-11.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2d", INT_MAX) : ft_printf("%-11.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10d", INT_MAX) : ft_printf("%-11.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0u", 0) : ft_printf("%-1.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1u", 0) : ft_printf("%-1.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2u", 0) : ft_printf("%-1.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10u", 0) : ft_printf("%-1.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0u", 0) : ft_printf("%-2.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1u", 0) : ft_printf("%-2.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2u", 0) : ft_printf("%-2.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10u", 0) : ft_printf("%-2.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0u", 0) : ft_printf("%-10.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1u", 0) : ft_printf("%-10.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2u", 0) : ft_printf("%-10.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10u", 0) : ft_printf("%-10.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0u", -1) : ft_printf("%-1.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1u", -1) : ft_printf("%-1.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2u", -1) : ft_printf("%-1.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10u", -1) : ft_printf("%-1.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0u", -1) : ft_printf("%-2.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1u", -1) : ft_printf("%-2.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2u", -1) : ft_printf("%-2.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10u", -1) : ft_printf("%-2.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0u", -1) : ft_printf("%-3.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1u", -1) : ft_printf("%-3.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2u", -1) : ft_printf("%-3.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10u", -1) : ft_printf("%-3.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0u", UINT_MAX) : ft_printf("%-9.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1u", UINT_MAX) : ft_printf("%-9.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2u", UINT_MAX) : ft_printf("%-9.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10u", UINT_MAX) : ft_printf("%-9.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0u", UINT_MAX) : ft_printf("%-10.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1u", UINT_MAX) : ft_printf("%-10.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2u", UINT_MAX) : ft_printf("%-10.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10u", UINT_MAX) : ft_printf("%-10.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0u", UINT_MAX) : ft_printf("%-11.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1u", UINT_MAX) : ft_printf("%-11.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2u", UINT_MAX) : ft_printf("%-11.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10u", UINT_MAX) : ft_printf("%-11.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0x", 0) : ft_printf("%-1.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1x", 0) : ft_printf("%-1.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2x", 0) : ft_printf("%-1.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10x", 0) : ft_printf("%-1.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0x", 0) : ft_printf("%-2.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1x", 0) : ft_printf("%-2.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2x", 0) : ft_printf("%-2.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10x", 0) : ft_printf("%-2.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0x", 0) : ft_printf("%-10.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1x", 0) : ft_printf("%-10.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2x", 0) : ft_printf("%-10.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10x", 0) : ft_printf("%-10.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0x", -1) : ft_printf("%-1.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1x", -1) : ft_printf("%-1.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2x", -1) : ft_printf("%-1.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10x", -1) : ft_printf("%-1.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0x", -1) : ft_printf("%-2.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1x", -1) : ft_printf("%-2.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2x", -1) : ft_printf("%-2.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10x", -1) : ft_printf("%-2.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0x", -1) : ft_printf("%-3.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1x", -1) : ft_printf("%-3.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2x", -1) : ft_printf("%-3.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10x", -1) : ft_printf("%-3.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0x", UINT_MAX) : ft_printf("%-9.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1x", UINT_MAX) : ft_printf("%-9.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2x", UINT_MAX) : ft_printf("%-9.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10x", UINT_MAX) : ft_printf("%-9.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0x", UINT_MAX) : ft_printf("%-10.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1x", UINT_MAX) : ft_printf("%-10.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2x", UINT_MAX) : ft_printf("%-10.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10x", UINT_MAX) : ft_printf("%-10.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0x", UINT_MAX) : ft_printf("%-11.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1x", UINT_MAX) : ft_printf("%-11.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2x", UINT_MAX) : ft_printf("%-11.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10x", UINT_MAX) : ft_printf("%-11.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0X", 0) : ft_printf("%-1.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1X", 0) : ft_printf("%-1.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2X", 0) : ft_printf("%-1.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10X", 0) : ft_printf("%-1.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0X", 0) : ft_printf("%-2.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1X", 0) : ft_printf("%-2.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2X", 0) : ft_printf("%-2.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10X", 0) : ft_printf("%-2.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0X", 0) : ft_printf("%-10.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1X", 0) : ft_printf("%-10.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2X", 0) : ft_printf("%-10.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10X", 0) : ft_printf("%-10.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.0X", -1) : ft_printf("%-1.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.1X", -1) : ft_printf("%-1.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.2X", -1) : ft_printf("%-1.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-1.10X", -1) : ft_printf("%-1.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.0X", -1) : ft_printf("%-2.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.1X", -1) : ft_printf("%-2.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.2X", -1) : ft_printf("%-2.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-2.10X", -1) : ft_printf("%-2.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.0X", -1) : ft_printf("%-3.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.1X", -1) : ft_printf("%-3.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.2X", -1) : ft_printf("%-3.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-3.10X", -1) : ft_printf("%-3.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.0X", UINT_MAX) : ft_printf("%-9.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.1X", UINT_MAX) : ft_printf("%-9.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.2X", UINT_MAX) : ft_printf("%-9.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-9.10X", UINT_MAX) : ft_printf("%-9.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.0X", UINT_MAX) : ft_printf("%-10.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.1X", UINT_MAX) : ft_printf("%-10.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.2X", UINT_MAX) : ft_printf("%-10.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.10X", UINT_MAX) : ft_printf("%-10.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.0X", UINT_MAX) : ft_printf("%-11.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.1X", UINT_MAX) : ft_printf("%-11.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.2X", UINT_MAX) : ft_printf("%-11.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%-11.10X", UINT_MAX) : ft_printf("%-11.10X", UINT_MAX));

	// [H - Tests with minimum field width, flag 0 and .].
	if (nb == count++)
		return(ac == 2 ? printf("%01.0i", 0) : ft_printf("%01.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1i", 0) : ft_printf("%01.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2i", 0) : ft_printf("%01.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10i", 0) : ft_printf("%01.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0i", 0) : ft_printf("%02.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1i", 0) : ft_printf("%02.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2i", 0) : ft_printf("%02.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10i", 0) : ft_printf("%02.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0i", 0) : ft_printf("%010.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1i", 0) : ft_printf("%010.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2i", 0) : ft_printf("%010.2i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10i", 0) : ft_printf("%010.10i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0i", -1) : ft_printf("%01.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1i", -1) : ft_printf("%01.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2i", -1) : ft_printf("%01.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10i", -1) : ft_printf("%01.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0i", -1) : ft_printf("%02.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1i", -1) : ft_printf("%02.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2i", -1) : ft_printf("%02.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10i", -1) : ft_printf("%02.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0i", -1) : ft_printf("%03.0i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1i", -1) : ft_printf("%03.1i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2i", -1) : ft_printf("%03.2i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10i", -1) : ft_printf("%03.10i", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0i", INT_MAX) : ft_printf("%09.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1i", INT_MAX) : ft_printf("%09.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2i", INT_MAX) : ft_printf("%09.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10i", INT_MAX) : ft_printf("%09.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0i", INT_MAX) : ft_printf("%010.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1i", INT_MAX) : ft_printf("%010.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2i", INT_MAX) : ft_printf("%010.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10i", INT_MAX) : ft_printf("%010.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0i", INT_MAX) : ft_printf("%011.0i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1i", INT_MAX) : ft_printf("%011.1i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2i", INT_MAX) : ft_printf("%011.2i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10i", INT_MAX) : ft_printf("%011.10i", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0d", 0) : ft_printf("%01.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1d", 0) : ft_printf("%01.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2d", 0) : ft_printf("%01.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10d", 0) : ft_printf("%01.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0d", 0) : ft_printf("%02.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1d", 0) : ft_printf("%02.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2d", 0) : ft_printf("%02.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10d", 0) : ft_printf("%02.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0d", 0) : ft_printf("%010.0d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1d", 0) : ft_printf("%010.1d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2d", 0) : ft_printf("%010.2d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10d", 0) : ft_printf("%010.10d", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0d", -1) : ft_printf("%01.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1d", -1) : ft_printf("%01.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2d", -1) : ft_printf("%01.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10d", -1) : ft_printf("%01.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0d", -1) : ft_printf("%02.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1d", -1) : ft_printf("%02.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2d", -1) : ft_printf("%02.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10d", -1) : ft_printf("%02.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0d", -1) : ft_printf("%03.0d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1d", -1) : ft_printf("%03.1d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2d", -1) : ft_printf("%03.2d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10d", -1) : ft_printf("%03.10d", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0d", INT_MAX) : ft_printf("%09.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1d", INT_MAX) : ft_printf("%09.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2d", INT_MAX) : ft_printf("%09.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10d", INT_MAX) : ft_printf("%09.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0d", INT_MAX) : ft_printf("%010.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1d", INT_MAX) : ft_printf("%010.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2d", INT_MAX) : ft_printf("%010.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10d", INT_MAX) : ft_printf("%010.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0d", INT_MAX) : ft_printf("%011.0d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1d", INT_MAX) : ft_printf("%011.1d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2d", INT_MAX) : ft_printf("%011.2d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10d", INT_MAX) : ft_printf("%011.10d", INT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0u", 0) : ft_printf("%01.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1u", 0) : ft_printf("%01.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2u", 0) : ft_printf("%01.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10u", 0) : ft_printf("%01.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0u", 0) : ft_printf("%02.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1u", 0) : ft_printf("%02.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2u", 0) : ft_printf("%02.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10u", 0) : ft_printf("%02.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0u", 0) : ft_printf("%010.0u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1u", 0) : ft_printf("%010.1u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2u", 0) : ft_printf("%010.2u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10u", 0) : ft_printf("%010.10u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0u", -1) : ft_printf("%01.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1u", -1) : ft_printf("%01.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2u", -1) : ft_printf("%01.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10u", -1) : ft_printf("%01.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0u", -1) : ft_printf("%02.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1u", -1) : ft_printf("%02.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2u", -1) : ft_printf("%02.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10u", -1) : ft_printf("%02.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0u", -1) : ft_printf("%03.0u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1u", -1) : ft_printf("%03.1u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2u", -1) : ft_printf("%03.2u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10u", -1) : ft_printf("%03.10u", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0u", UINT_MAX) : ft_printf("%09.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1u", UINT_MAX) : ft_printf("%09.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2u", UINT_MAX) : ft_printf("%09.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10u", UINT_MAX) : ft_printf("%09.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0u", UINT_MAX) : ft_printf("%010.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1u", UINT_MAX) : ft_printf("%010.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2u", UINT_MAX) : ft_printf("%010.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10u", UINT_MAX) : ft_printf("%010.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0u", UINT_MAX) : ft_printf("%011.0u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1u", UINT_MAX) : ft_printf("%011.1u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2u", UINT_MAX) : ft_printf("%011.2u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10u", UINT_MAX) : ft_printf("%011.10u", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0x", 0) : ft_printf("%01.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1x", 0) : ft_printf("%01.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2x", 0) : ft_printf("%01.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10x", 0) : ft_printf("%01.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0x", 0) : ft_printf("%02.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1x", 0) : ft_printf("%02.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2x", 0) : ft_printf("%02.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10x", 0) : ft_printf("%02.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0x", 0) : ft_printf("%010.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1x", 0) : ft_printf("%010.1x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2x", 0) : ft_printf("%010.2x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10x", 0) : ft_printf("%010.10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0x", -1) : ft_printf("%01.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1x", -1) : ft_printf("%01.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2x", -1) : ft_printf("%01.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10x", -1) : ft_printf("%01.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0x", -1) : ft_printf("%02.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1x", -1) : ft_printf("%02.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2x", -1) : ft_printf("%02.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10x", -1) : ft_printf("%02.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0x", -1) : ft_printf("%03.0x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1x", -1) : ft_printf("%03.1x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2x", -1) : ft_printf("%03.2x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10x", -1) : ft_printf("%03.10x", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0x", UINT_MAX) : ft_printf("%09.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1x", UINT_MAX) : ft_printf("%09.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2x", UINT_MAX) : ft_printf("%09.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10x", UINT_MAX) : ft_printf("%09.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0x", UINT_MAX) : ft_printf("%010.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1x", UINT_MAX) : ft_printf("%010.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2x", UINT_MAX) : ft_printf("%010.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10x", UINT_MAX) : ft_printf("%010.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0x", UINT_MAX) : ft_printf("%011.0x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1x", UINT_MAX) : ft_printf("%011.1x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2x", UINT_MAX) : ft_printf("%011.2x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10x", UINT_MAX) : ft_printf("%011.10x", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0X", 0) : ft_printf("%01.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1X", 0) : ft_printf("%01.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2X", 0) : ft_printf("%01.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10X", 0) : ft_printf("%01.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0X", 0) : ft_printf("%02.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1X", 0) : ft_printf("%02.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2X", 0) : ft_printf("%02.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10X", 0) : ft_printf("%02.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0X", 0) : ft_printf("%010.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1X", 0) : ft_printf("%010.1X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2X", 0) : ft_printf("%010.2X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10X", 0) : ft_printf("%010.10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%01.0X", -1) : ft_printf("%01.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.1X", -1) : ft_printf("%01.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.2X", -1) : ft_printf("%01.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%01.10X", -1) : ft_printf("%01.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.0X", -1) : ft_printf("%02.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.1X", -1) : ft_printf("%02.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.2X", -1) : ft_printf("%02.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%02.10X", -1) : ft_printf("%02.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.0X", -1) : ft_printf("%03.0X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.1X", -1) : ft_printf("%03.1X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.2X", -1) : ft_printf("%03.2X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%03.10X", -1) : ft_printf("%03.10X", -1));
	if (nb == count++)
		return(ac == 2 ? printf("%09.0X", UINT_MAX) : ft_printf("%09.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.1X", UINT_MAX) : ft_printf("%09.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.2X", UINT_MAX) : ft_printf("%09.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%09.10X", UINT_MAX) : ft_printf("%09.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.0X", UINT_MAX) : ft_printf("%010.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.1X", UINT_MAX) : ft_printf("%010.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.2X", UINT_MAX) : ft_printf("%010.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%010.10X", UINT_MAX) : ft_printf("%010.10X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.0X", UINT_MAX) : ft_printf("%011.0X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.1X", UINT_MAX) : ft_printf("%011.1X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.2X", UINT_MAX) : ft_printf("%011.2X", UINT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%011.10X", UINT_MAX) : ft_printf("%011.10X", UINT_MAX));
	
	// [I - Tests with *].
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 0, 42) : ft_printf("%*d", 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 0, 0) : ft_printf("%*d", 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 10, 42) : ft_printf("%*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", -10, 42) : ft_printf("%*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", -10, 42) : ft_printf("%0*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 10, 42) : ft_printf("%0*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 10, -42) : ft_printf("%0*d", 10, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 0, 42) : ft_printf("%0*d", 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", 10, 0) : ft_printf("%0*d", 10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%0*d", -10, 0) : ft_printf("%0*d", -10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*d", 010, 42) : ft_printf("%*d", 010, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*s", 10, "Hello") : ft_printf("%*s", 10, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*s", -10, "Hello") : ft_printf("%*s", -10, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%-*d", 10, 42) : ft_printf("%-*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%-*d", -10, 42) : ft_printf("%-*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%-*d", -10, -42) : ft_printf("%-*d", -10, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 0, 42) : ft_printf("%.*d", 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 10, 42) : ft_printf("%.*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -10, 42) : ft_printf("%.*d", -10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 0, 0) : ft_printf("%.*d", 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", 10, 0) : ft_printf("%.*d", 10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -10, 0) : ft_printf("%.*d", -10, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -0, 0) : ft_printf("%.*d", -0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -0, 42) : ft_printf("%.*d", -0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*d", -0, -42) : ft_printf("%.*d", -0, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%.*s", -3, "Hello") : ft_printf("%.*s", -3, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%10.*d", 10, 42) : ft_printf("%10.*d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.10d", 10, 42) : ft_printf("%*.10d", 10, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 0, 0) : ft_printf("%*.*d", 0, 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 0, 42) : ft_printf("%*.*d", 0, 0, 42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 0, -42) : ft_printf("%*.*d", 0, 0, -42));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, 5, 0) : ft_printf("%*.*d", 0, 5, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 0, -5, 0) : ft_printf("%*.*d", 0, -5, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 5, 0, 0) : ft_printf("%*.*d", 5, 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", -5, 0, 0) : ft_printf("%*.*d", -5, 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*d", 5, 5, 0) : ft_printf("%*.*d", 5, 5, 0));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 0, "Hello") : ft_printf("%*.*s", 0, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 0, "Hello") : ft_printf("%*.*s", 0, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 0, "Hello") : ft_printf("%*.*s", 0, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, 5, "Hello") : ft_printf("%*.*s", 0, 5, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 0, -5, "Hello") : ft_printf("%*.*s", 0, -5, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 5, 0, "Hello") : ft_printf("%*.*s", 5, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", -5, 0, "Hello") : ft_printf("%*.*s", -5, 0, "Hello"));
	if (nb == count++)
		return(ac == 2 ? printf("%*.*s", 5, 5, "Hello") : ft_printf("%*.*s", 5, 5, "Hello"));
	
	// [J - Tests with n].
	int		t1 = -1;
	int		t2 = -1;
	int		t1bis = -1;
	int		t2bis = -1;
	if (nb == count++)
		return(ac == 2 ? printf("%n", NULL) : ft_printf("%n", NULL));
	if (nb == count++)
	{
		if (ac == 2)
			printf("123%n ", &t1);
		else
			ft_printf("123%n ", &t2);
		return(ac == 2 ? printf("size = %d", t1) : ft_printf("size = %d", t2));
	}
	if (nb == count++)
	{
		if (ac == 2)
			printf("%n ", &t1);
		else
			ft_printf("%n ", &t2);
		return(ac == 2 ? printf("size = %d", t1) : ft_printf("size = %d", t2));
	}
	if (nb == count++)
	{
		if (ac == 2)
			printf("%s %n ", "Hello", &t1);
		else
			ft_printf("%s %n ", "Hello", &t2);
		return(ac == 2 ? printf("size = %d", t1) : ft_printf("size = %d", t2));
	}
	if (nb == count++)
	{
		if (ac == 2)
			printf("%10s %n ", "Hello", &t1);
		else
			ft_printf("%10s %n ", "Hello", &t2);
		return(ac == 2 ? printf("size = %d", t1) : ft_printf("size = %d", t2));
	}
	if (nb == count++)
	{
		if (ac == 2)
			printf("%10.2s %n ", "Hello", &t1);
		else
			ft_printf("%10.2s %n ", "Hello", &t2);
		return(ac == 2 ? printf("size = %d", t1) : ft_printf("size = %d", t2));
	}
	if (nb == count++)
	{
		if (ac == 2)
			printf("%10.2s %n %s %n", "Hello", &t1, "Hello2", &t1bis);
		else
			ft_printf("%10.2s %n %s %n", "Hello", &t2, "Hello2", &t2bis);
		return(ac == 2 ? printf("size = %d ; size = %d", t1, t1bis) : ft_printf("size = %d ; size = %d", t2, t2bis));
	}

	// [K - Tests with f].
	if (nb == count++)
		return(ac == 2 ? printf("%f", 0) : ft_printf("%f", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%.f", 42.0) : ft_printf("%.f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1f", 42.0) : ft_printf("%.1f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.f", 42.1) : ft_printf("%.f", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 42.0) : ft_printf("%f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 42.1) : ft_printf("%f", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 42.101) : ft_printf("%f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 42.002) : ft_printf("%f", 42.002));
	if (nb == count++)
		return(ac == 2 ? printf("%12f", 42.0) : ft_printf("%12f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%1f", 42.0) : ft_printf("%1f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%12f", 42.101) : ft_printf("%12f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%-12f", 42.101) : ft_printf("%-12f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%012f", 42.101) : ft_printf("%012f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%0-12f", 42.101) : ft_printf("%0-12f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.2f", 42.101) : ft_printf("%.2f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 42.101) : ft_printf("%.0f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.f", 42.101) : ft_printf("%.0f", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", 42.121) : ft_printf("%.8f", 42.121));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", 1234567890123456.1) : ft_printf("%.8f", 1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", 12345678901234567.1) : ft_printf("%.8f", 12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", 123456789012345678.1) : ft_printf("%.8f", 123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", INT_MAX - 40 + 0.1) : ft_printf("%.8f", INT_MAX - 40 + 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70f", 42.10115645159842215121541215412126) : ft_printf("%.70f", 42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%.120f", 42.123564897979861111000012356489797986111100001235648979123564897979861111000012356489797986111100001235648979798611110000123564897979861111000012356489797986111100009999999999999999999999999999999999999999999999999999999999999999999) : ft_printf("%.120f", 42.12356489797986111100001235648979798611110000123564897912356489797986111100001235648979798611110000123564897979861111000012356489797986111100001235648979798611110000119999999999999999999999999999999999999999999999999999999999999999999));
	if (nb == count++)
		return(ac == 2 ? printf("%040.8f", 1234567890123456.1) : ft_printf("%040.8f", 1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-40.8f", 12345678901234567.1) : ft_printf("%-40.8f", 12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%0-40.8f", 123456789012345678.1) : ft_printf("%0-40.8f", 123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", INT_MAX - 40 + 0.1) : ft_printf("%.8f", INT_MAX - 40 + 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70f", 42.10115645159842215121541215412126) : ft_printf("%.70f", 42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%.3f", 9.9997) : ft_printf("%.3f", 9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%07.3f", 9.9997) : ft_printf("%07.3f", 9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%f", -42.0) : ft_printf("%f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%f", -42.1) : ft_printf("%f", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%f", -42.101) : ft_printf("%f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%f", -42.002) : ft_printf("%f", -42.002));
	if (nb == count++)
		return(ac == 2 ? printf("%12f", -42.0) : ft_printf("%12f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%1f", -42.0) : ft_printf("%1f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%12f", -42.101) : ft_printf("%12f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%-12f", -42.101) : ft_printf("%-12f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%012f", -42.101) : ft_printf("%012f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%0-12f", -42.101) : ft_printf("%0-12f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.2f", -42.101) : ft_printf("%.2f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", -42.101) : ft_printf("%.0f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.f", -42.101) : ft_printf("%.0f", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", -42.121) : ft_printf("%.8f", -42.121));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", -1234567890123456.1) : ft_printf("%.8f", -1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", -12345678901234567.1) : ft_printf("%.8f", -12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8f", -123456789012345678.1) : ft_printf("%.8f", -123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70f", -42.10115645159842215121541215412126) : ft_printf("%.70f", -42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%040.8f", -1234567890123456.1) : ft_printf("%040.8f", -1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-40.8f", -12345678901234567.1) : ft_printf("%-40.8f", -12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%0-40.8f", -123456789012345678.1) : ft_printf("%0-40.8f", -123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70f", -42.10115645159842215121541215412126) : ft_printf("%.70f", -42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%.3f", -9.9997) : ft_printf("%.3f", -9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%07.3f", -9.9997) : ft_printf("%07.3f", -9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 0.1) : ft_printf("%f", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 0.2) : ft_printf("%f", 0.2));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 0.01) : ft_printf("%f", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%f", -0.1) : ft_printf("%f", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%f", -0.2) : ft_printf("%f", -0.2));
	if (nb == count++)
		return(ac == 2 ? printf("%f", -0.01) : ft_printf("%f", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 0.0000000056) : ft_printf("%f", 0.0000000056));
	if (nb == count++)
		return(ac == 2 ? printf("%010f", 0.01) : ft_printf("%010f", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10f", 0.01) : ft_printf("%-10f", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10f", 0.42) : ft_printf("%-10f", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%f", 0.0101010101010101) : ft_printf("%f", 0.0101010101010101));
	if (nb == count++)
		return(ac == 2 ? printf("%.f", 0.1) : ft_printf("%.f", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 0.1) : ft_printf("%.0f", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1f", 0.2) : ft_printf("%.1f", 0.2));
	if (nb == count++)
		return(ac == 2 ? printf("%.1f", 0.01) : ft_printf("%.1f", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", -0.1) : ft_printf("%.0f", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.12f", 0.0000000056) : ft_printf("%.12f", 0.0000000056));
	if (nb == count++)
		return(ac == 2 ? printf("%.20f", 0.0101010101010101) : ft_printf("%.20f", 0.0101010101010101));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 2.51) : ft_printf("%.0f", 2.51));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 1.5) : ft_printf("%.0f", 1.5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 4.5) : ft_printf("%.0f", 4.5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", -2.5) : ft_printf("%.0f", -2.5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", -3.5) : ft_printf("%.0f", -3.5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 2.5) : ft_printf("%.0f", 2.5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 3.5) : ft_printf("%.0f", 3.5));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 2.45) : ft_printf("%.0f", 2.45));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 2.35) : ft_printf("%.0f", 2.35));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", -2.35) : ft_printf("%.0f", -2.35));
	if (nb == count++)
		return(ac == 2 ? printf("%.0f", 3.451) : ft_printf("%.0f", 3.451));

	// [L - Tests with e].
	if (nb == count++)
		return(ac == 2 ? printf("%.4e", 150.129) : ft_printf("%.4e", 150.129));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 0.0) : ft_printf("%e", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 42.0) : ft_printf("%e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 42.1) : ft_printf("%e", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 42.101) : ft_printf("%e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 42.002) : ft_printf("%e", 42.002));
	if (nb == count++)
		return(ac == 2 ? printf("%12e", 42.0) : ft_printf("%12e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%1e", 42.0) : ft_printf("%1e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%12e", 42.101) : ft_printf("%12e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%-12e", 42.101) : ft_printf("%-12e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%012e", 42.101) : ft_printf("%012e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%0-12e", 42.101) : ft_printf("%0-12e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.2e", 42.101) : ft_printf("%.2e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.0e", 42.101) : ft_printf("%.0e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.e", 42.101) : ft_printf("%.0e", 42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", 42.121) : ft_printf("%.8e", 42.121));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", 1234567890123456.1) : ft_printf("%.8e", 1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", 12345678901234567.1) : ft_printf("%.8e", 12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", 123456789012345678.1) : ft_printf("%.8e", 123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", INT_MAX - 40 + 0.1) : ft_printf("%.8e", INT_MAX - 40 + 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70e", 42.10115645159842215121541215412126) : ft_printf("%.70e", 42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%040.8e", 1234567890123456.1) : ft_printf("%040.8e", 1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-40.8e", 12345678901234567.1) : ft_printf("%-40.8e", 12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%0-40.8e", 123456789012345678.1) : ft_printf("%0-40.8e", 123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", INT_MAX - 40 + 0.1) : ft_printf("%.8e", INT_MAX - 40 + 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70e", 42.10115645159842215121541215412126) : ft_printf("%.70e", 42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%.3e", 9.9997) : ft_printf("%.3e", 9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%07.3e", 9.9997) : ft_printf("%07.3e", 9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%e", -42.0) : ft_printf("%e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%e", -42.1) : ft_printf("%e", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%e", -42.101) : ft_printf("%e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%e", -42.002) : ft_printf("%e", -42.002));
	if (nb == count++)
		return(ac == 2 ? printf("%12e", -42.0) : ft_printf("%12e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%1e", -42.0) : ft_printf("%1e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%12e", -42.101) : ft_printf("%12e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%-12e", -42.101) : ft_printf("%-12e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%012e", -42.101) : ft_printf("%012e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%0-12e", -42.101) : ft_printf("%0-12e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.2e", -42.101) : ft_printf("%.2e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.0e", -42.101) : ft_printf("%.0e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.e", -42.101) : ft_printf("%.0e", -42.101));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", -42.121) : ft_printf("%.8e", -42.121));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", -1234567890123456.1) : ft_printf("%.8e", -1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", -12345678901234567.1) : ft_printf("%.8e", -12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.8e", -123456789012345678.1) : ft_printf("%.8e", -123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70e", -42.10115645159842215121541215412126) : ft_printf("%.70e", -42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%040.8e", -1234567890123456.1) : ft_printf("%040.8e", -1234567890123456.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-40.8e", -12345678901234567.1) : ft_printf("%-40.8e", -12345678901234567.1));
	if (nb == count++)
		return(ac == 2 ? printf("%0-40.8e", -123456789012345678.1) : ft_printf("%0-40.8e", -123456789012345678.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.70e", -42.10115645159842215121541215412126) : ft_printf("%.70e", -42.10115645159842215121541215412126));
	if (nb == count++)
		return(ac == 2 ? printf("%.3e", -9.9997) : ft_printf("%.3e", -9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%07.3e", -9.9997) : ft_printf("%07.3e", -9.9997));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 0.1) : ft_printf("%e", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 0.2) : ft_printf("%e", 0.2));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 0.01) : ft_printf("%e", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%e", -0.1) : ft_printf("%e", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%e", -0.2) : ft_printf("%e", -0.2));
	if (nb == count++)
		return(ac == 2 ? printf("%e", -0.01) : ft_printf("%e", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 0.0000000056) : ft_printf("%e", 0.0000000056));
	if (nb == count++)
		return(ac == 2 ? printf("%010e", 0.01) : ft_printf("%010e", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10e", 0.01) : ft_printf("%-10e", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10e", 0.42) : ft_printf("%-10e", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%e", 0.0101010101010101) : ft_printf("%e", 0.0101010101010101));
	if (nb == count++)
		return(ac == 2 ? printf("%.e", 0.1) : ft_printf("%.e", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0e", 0.1) : ft_printf("%.0e", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1e", 0.2) : ft_printf("%.1e", 0.2));
	if (nb == count++)
		return(ac == 2 ? printf("%.1e", 0.01) : ft_printf("%.1e", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.0e", -0.1) : ft_printf("%.0e", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.12e", 0.0000000056) : ft_printf("%.12e", 0.0000000056));

	// [M - Tests with g].
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.0) : ft_printf("%g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 42.0) : ft_printf("%g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 1.0) : ft_printf("%g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 100.0) : ft_printf("%g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.1) : ft_printf("%g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.1001000001) : ft_printf("%g", 0.1001000001));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.0101010101) : ft_printf("%g", 0.0101010101));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.42) : ft_printf("%g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 42.1) : ft_printf("%g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.01) : ft_printf("%g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.0101) : ft_printf("%g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.00042) : ft_printf("%g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%g", 0.000423) : ft_printf("%g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%g", INT_MAX + 1.0) : ft_printf("%g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -42.0) : ft_printf("%g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -1.0) : ft_printf("%g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -100.0) : ft_printf("%g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -0.1) : ft_printf("%g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -0.42) : ft_printf("%g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -42.1) : ft_printf("%g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -0.01) : ft_printf("%g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -0.0101) : ft_printf("%g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -0.00042) : ft_printf("%g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%g", -0.000423) : ft_printf("%g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%g", INT_MIN - 1.0) : ft_printf("%g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 0.0) : ft_printf("%.g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 42.0) : ft_printf("%.g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 1.0) : ft_printf("%.g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 100.0) : ft_printf("%.g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 0.1) : ft_printf("%.g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 0.42) : ft_printf("%.g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 42.1) : ft_printf("%.g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 0.01) : ft_printf("%.g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 0.0101) : ft_printf("%.g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 0.00042) : ft_printf("%.g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 0.000423) : ft_printf("%.g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", INT_MAX + 1.0) : ft_printf("%.g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -42.0) : ft_printf("%.g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -1.0) : ft_printf("%.g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -100.0) : ft_printf("%.g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -0.1) : ft_printf("%.g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -0.42) : ft_printf("%.g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -42.1) : ft_printf("%.g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -0.01) : ft_printf("%.g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -0.0101) : ft_printf("%.g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -0.00042) : ft_printf("%.g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -0.000423) : ft_printf("%.g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", INT_MIN - 1.0) : ft_printf("%.g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 0.0) : ft_printf("%.0g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 42.0) : ft_printf("%.0g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 1.0) : ft_printf("%.0g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 100.0) : ft_printf("%.0g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 0.1) : ft_printf("%.0g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 0.42) : ft_printf("%.0g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 42.1) : ft_printf("%.0g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 0.01) : ft_printf("%.0g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 0.0101) : ft_printf("%.0g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 0.00042) : ft_printf("%.0g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", 0.000423) : ft_printf("%.0g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", INT_MAX + 1.0) : ft_printf("%.0g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -42.0) : ft_printf("%.0g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -1.0) : ft_printf("%.0g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -100.0) : ft_printf("%.0g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -0.1) : ft_printf("%.0g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -0.42) : ft_printf("%.0g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -42.1) : ft_printf("%.0g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -0.01) : ft_printf("%.0g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -0.0101) : ft_printf("%.0g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -0.00042) : ft_printf("%.0g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", -0.000423) : ft_printf("%.0g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.0g", INT_MIN - 1.0) : ft_printf("%.0g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 0.0) : ft_printf("%.1g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 42.0) : ft_printf("%.1g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 1.0) : ft_printf("%.1g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 100.0) : ft_printf("%.1g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 0.1) : ft_printf("%.1g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 0.42) : ft_printf("%.1g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 42.1) : ft_printf("%.1g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 0.01) : ft_printf("%.1g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 0.0101) : ft_printf("%.1g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 0.00042) : ft_printf("%.1g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", 0.000423) : ft_printf("%.1g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", INT_MAX + 1.0) : ft_printf("%.1g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -42.0) : ft_printf("%.1g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -1.0) : ft_printf("%.1g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -100.0) : ft_printf("%.1g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -0.1) : ft_printf("%.1g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -0.42) : ft_printf("%.1g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -42.1) : ft_printf("%.1g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -0.01) : ft_printf("%.1g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -0.0101) : ft_printf("%.1g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -0.00042) : ft_printf("%.1g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", -0.000423) : ft_printf("%.1g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.1g", INT_MIN - 1.0) : ft_printf("%.1g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 0.0) : ft_printf("%.2g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 42.0) : ft_printf("%.2g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 1.0) : ft_printf("%.2g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 100.0) : ft_printf("%.2g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 0.1) : ft_printf("%.2g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 0.42) : ft_printf("%.2g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 42.1) : ft_printf("%.2g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 0.01) : ft_printf("%.2g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 0.0101) : ft_printf("%.2g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 0.00042) : ft_printf("%.2g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 0.000423) : ft_printf("%.2g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", INT_MAX + 1.0) : ft_printf("%.2g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -42.0) : ft_printf("%.2g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -1.0) : ft_printf("%.2g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -100.0) : ft_printf("%.2g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -0.1) : ft_printf("%.2g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -0.42) : ft_printf("%.2g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -42.1) : ft_printf("%.2g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -0.01) : ft_printf("%.2g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -0.0101) : ft_printf("%.2g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -0.00042) : ft_printf("%.2g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", -0.000423) : ft_printf("%.2g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", INT_MIN - 1.0) : ft_printf("%.2g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 56789.0) : ft_printf("%.2g", 56789.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 56789.1) : ft_printf("%.2g", 56789.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.2g", 56789.12) : ft_printf("%.2g", 56789.12));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 56789.12) : ft_printf("%.g", 56789.12));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", 54789.12) : ft_printf("%.g", 54789.12));
	if (nb == count++)
		return(ac == 2 ? printf("%.g", -54789.12) : ft_printf("%.g", -54789.12));
	if (nb == count++)
		return(ac == 2 ? printf("%20.g", -54789.12) : ft_printf("%20.g", -54789.12));
	if (nb == count++)
		return(ac == 2 ? printf("%020.g", -54789.12) : ft_printf("%020.g", -54789.12));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.0) : ft_printf("%.3g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 42.0) : ft_printf("%.3g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 1.0) : ft_printf("%.3g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 100.0) : ft_printf("%.3g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.1) : ft_printf("%.3g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.42) : ft_printf("%.3g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 42.1) : ft_printf("%.3g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.01) : ft_printf("%.3g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.0101) : ft_printf("%.3g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.00042) : ft_printf("%.3g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.000423) : ft_printf("%.3g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", INT_MAX + 1.0) : ft_printf("%.3g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -42.0) : ft_printf("%.3g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -1.0) : ft_printf("%.3g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -100.0) : ft_printf("%.3g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.1) : ft_printf("%.3g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.42) : ft_printf("%.3g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -42.1) : ft_printf("%.3g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.01) : ft_printf("%.3g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.0101) : ft_printf("%.3g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.00042) : ft_printf("%.3g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.000423) : ft_printf("%.3g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", INT_MIN - 1.0) : ft_printf("%.3g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.0) : ft_printf("%.3g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 42.0) : ft_printf("%.3g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 1.0) : ft_printf("%.3g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 100.0) : ft_printf("%.3g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.1) : ft_printf("%.3g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.42) : ft_printf("%.3g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 42.1) : ft_printf("%.3g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.01) : ft_printf("%.3g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.0101) : ft_printf("%.3g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.00042) : ft_printf("%.3g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", 0.000423) : ft_printf("%.3g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", INT_MAX + 1.0) : ft_printf("%.3g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -42.0) : ft_printf("%.3g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -1.0) : ft_printf("%.3g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -100.0) : ft_printf("%.3g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.1) : ft_printf("%.3g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.42) : ft_printf("%.3g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -42.1) : ft_printf("%.3g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.01) : ft_printf("%.3g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.0101) : ft_printf("%.3g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.00042) : ft_printf("%.3g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", -0.000423) : ft_printf("%.3g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.3g", INT_MIN - 1.0) : ft_printf("%.3g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 0.0) : ft_printf("%.5g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 42.0) : ft_printf("%.5g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 1.0) : ft_printf("%.5g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 100.0) : ft_printf("%.5g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 0.1) : ft_printf("%.5g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 0.42) : ft_printf("%.5g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 42.1) : ft_printf("%.5g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 0.01) : ft_printf("%.5g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 0.0101) : ft_printf("%.5g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 0.00042) : ft_printf("%.5g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", 0.000423) : ft_printf("%.5g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", INT_MAX + 1.0) : ft_printf("%.5g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -42.0) : ft_printf("%.5g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -1.0) : ft_printf("%.5g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -100.0) : ft_printf("%.5g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -0.1) : ft_printf("%.5g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -0.42) : ft_printf("%.5g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -42.1) : ft_printf("%.5g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -0.01) : ft_printf("%.5g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -0.0101) : ft_printf("%.5g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -0.00042) : ft_printf("%.5g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", -0.000423) : ft_printf("%.5g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%.5g", INT_MIN - 1.0) : ft_printf("%.5g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%g", DBL_MAX) : ft_printf("%g", DBL_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%g", DBL_MAX + 1) : ft_printf("%g", DBL_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.0) : ft_printf("%010.3g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 42.0) : ft_printf("%010.3g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 1.0) : ft_printf("%010.3g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 100.0) : ft_printf("%010.3g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.1) : ft_printf("%010.3g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.42) : ft_printf("%010.3g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 42.1) : ft_printf("%010.3g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.01) : ft_printf("%010.3g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.0101) : ft_printf("%010.3g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.00042) : ft_printf("%010.3g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.000423) : ft_printf("%010.3g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", INT_MAX + 1.0) : ft_printf("%010.3g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -42.0) : ft_printf("%010.3g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -1.0) : ft_printf("%010.3g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -100.0) : ft_printf("%010.3g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.1) : ft_printf("%010.3g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.42) : ft_printf("%010.3g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -42.1) : ft_printf("%010.3g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.01) : ft_printf("%010.3g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.0101) : ft_printf("%010.3g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.00042) : ft_printf("%010.3g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.000423) : ft_printf("%010.3g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", INT_MIN - 1.0) : ft_printf("%010.3g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.0) : ft_printf("%010.3g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 42.0) : ft_printf("%010.3g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 1.0) : ft_printf("%010.3g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 100.0) : ft_printf("%010.3g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.1) : ft_printf("%010.3g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.42) : ft_printf("%010.3g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 42.1) : ft_printf("%010.3g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.01) : ft_printf("%010.3g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.0101) : ft_printf("%010.3g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.00042) : ft_printf("%010.3g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", 0.000423) : ft_printf("%010.3g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", INT_MAX + 1.0) : ft_printf("%010.3g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -42.0) : ft_printf("%010.3g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -1.0) : ft_printf("%010.3g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -100.0) : ft_printf("%010.3g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.1) : ft_printf("%010.3g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.42) : ft_printf("%010.3g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -42.1) : ft_printf("%010.3g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.01) : ft_printf("%010.3g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.0101) : ft_printf("%010.3g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.00042) : ft_printf("%010.3g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", -0.000423) : ft_printf("%010.3g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%010.3g", INT_MIN - 1.0) : ft_printf("%010.3g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010.6g", 100000000.0) : ft_printf("%010.6g", 100000000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%020.9g", 1000420000.0) : ft_printf("%020.9g", 1000420000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.0) : ft_printf("%-10.3g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 42.0) : ft_printf("%-10.3g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 1.0) : ft_printf("%-10.3g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 100.0) : ft_printf("%-10.3g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.1) : ft_printf("%-10.3g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.42) : ft_printf("%-10.3g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 42.1) : ft_printf("%-10.3g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.01) : ft_printf("%-10.3g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.0101) : ft_printf("%-10.3g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.00042) : ft_printf("%-10.3g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.000423) : ft_printf("%-10.3g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", INT_MAX + 1.0) : ft_printf("%-10.3g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -42.0) : ft_printf("%-10.3g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -1.0) : ft_printf("%-10.3g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -100.0) : ft_printf("%-10.3g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.1) : ft_printf("%-10.3g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.42) : ft_printf("%-10.3g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -42.1) : ft_printf("%-10.3g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.01) : ft_printf("%-10.3g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.0101) : ft_printf("%-10.3g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.00042) : ft_printf("%-10.3g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.000423) : ft_printf("%-10.3g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", INT_MIN - 1.0) : ft_printf("%-10.3g", INT_MIN - 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.0) : ft_printf("%-10.3g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 42.0) : ft_printf("%-10.3g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 1.0) : ft_printf("%-10.3g", 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 100.0) : ft_printf("%-10.3g", 100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.1) : ft_printf("%-10.3g", 0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.42) : ft_printf("%-10.3g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 42.1) : ft_printf("%-10.3g", 42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.01) : ft_printf("%-10.3g", 0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.0101) : ft_printf("%-10.3g", 0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.00042) : ft_printf("%-10.3g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", 0.000423) : ft_printf("%-10.3g", 0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", INT_MAX + 1.0) : ft_printf("%-10.3g", INT_MAX + 1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -42.0) : ft_printf("%-10.3g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -1.0) : ft_printf("%-10.3g", -1.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -100.0) : ft_printf("%-10.3g", -100.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.1) : ft_printf("%-10.3g", -0.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.42) : ft_printf("%-10.3g", -0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -42.1) : ft_printf("%-10.3g", -42.1));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.01) : ft_printf("%-10.3g", -0.01));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.0101) : ft_printf("%-10.3g", -0.0101));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.00042) : ft_printf("%-10.3g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", -0.000423) : ft_printf("%-10.3g", -0.000423));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3g", INT_MIN - 1.0) : ft_printf("%-10.3g", INT_MIN - 1.0));

	// [N - Tests with length modifiers].
	if (nb == count++)
		return(ac == 2 ? printf("%c", 0b01000001) : ft_printf("%c", 0b01000001));
	if (nb == count++)
		return(ac == 2 ? printf("%hhi", CHAR_MAX) : ft_printf("%hhi", CHAR_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%hhi", CHAR_MAX + 1) : ft_printf("%hhi", CHAR_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%hhi", CHAR_MIN) : ft_printf("%hhi", CHAR_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%hhi", CHAR_MIN - 1) : ft_printf("%hhi", CHAR_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%hhu", UCHAR_MAX) : ft_printf("%hhu", UCHAR_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%hhu", UCHAR_MAX + 1) : ft_printf("%hhu", UCHAR_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%hhx", UCHAR_MAX) : ft_printf("%hhx", UCHAR_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%hhx", UCHAR_MAX + 1) : ft_printf("%hhx", UCHAR_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%hi", SHRT_MAX) : ft_printf("%hi", SHRT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%hi", SHRT_MAX + 1) : ft_printf("%hi", SHRT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%hi", SHRT_MIN) : ft_printf("%hi", SHRT_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%hi", SHRT_MIN - 1) : ft_printf("%hi", SHRT_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%hu", USHRT_MAX) : ft_printf("%hu", USHRT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%hu", USHRT_MAX + 1) : ft_printf("%hu", USHRT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%hx", USHRT_MAX) : ft_printf("%hx", USHRT_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%hx", USHRT_MAX + 1) : ft_printf("%hx", USHRT_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%li", LONG_MAX) : ft_printf("%li", LONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%li", LONG_MAX + 1) : ft_printf("%li", LONG_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%li", LONG_MIN) : ft_printf("%li", LONG_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%li", LONG_MIN - 1) : ft_printf("%li", LONG_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%lu", ULONG_MAX) : ft_printf("%lu", ULONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%lu", ULONG_MAX + 1) : ft_printf("%lu", ULONG_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%lx", ULONG_MAX) : ft_printf("%lx", ULONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%lx", ULONG_MAX + 1) : ft_printf("%lx", ULONG_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%lli", LLONG_MAX) : ft_printf("%lli", LLONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%lli", LLONG_MAX + 1) : ft_printf("%lli", LLONG_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%lli", LLONG_MIN) : ft_printf("%lli", LLONG_MIN));
	if (nb == count++)
		return(ac == 2 ? printf("%lli", LLONG_MIN - 1) : ft_printf("%lli", LLONG_MIN - 1));
	if (nb == count++)
		return(ac == 2 ? printf("%llu", ULLONG_MAX) : ft_printf("%llu", ULLONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%llu", ULLONG_MAX + 1) : ft_printf("%llu", ULLONG_MAX + 1));
	if (nb == count++)
		return(ac == 2 ? printf("%llx", ULLONG_MAX) : ft_printf("%llx", ULLONG_MAX));
	if (nb == count++)
		return(ac == 2 ? printf("%llx", ULLONG_MAX + 1) : ft_printf("%llx", ULLONG_MAX + 1));
	int		t3 = -1;
	int		t4 = -1;
	char	s[200];
	int		i = 199;
	while (i--)
		s[i] = '0';
	s[199] = 0;
	if (nb == count++)
	{
		if (ac == 2)
			printf("%s%hhn ", s, &t3);
		else
			ft_printf("%s%hhn ", s, &t4);
		return(ac == 2 ? printf("size = %d", t3) : ft_printf("size = %d", t4));
	}
	setlocale(LC_ALL, "");
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 128519) : ft_printf("%lc ", 128519));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0x80000) : ft_printf("%lc ", 0x80000));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 176) : ft_printf("%lc ", 176));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 35211) : ft_printf("%lc ", 35211));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0x7E) : ft_printf("%lc ", 0x7E));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0x7F) : ft_printf("%lc ", 0x7F));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0x80) : ft_printf("%lc ", 0x80));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0x7FF) : ft_printf("%lc ", 0x7FF));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0x800) : ft_printf("%lc ", 0x800));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0xFFFF) : ft_printf("%lc ", 0xFFFF));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 0x80000) : ft_printf("%lc ", 0x80000));
	if (nb == count++)
		return(ac == 2 ? printf("%lc %lc ", 0x13143, 0x13144) : ft_printf("%lc %lc ", 0x13143, 0x13144));
	if (nb == count++)
		return(ac == 2 ? printf("%lc ", 256 + 48) : ft_printf("%lc ", 256 + 48));
	if (nb == count++)
		return(ac == 2 ? printf("%6lc ", 176) : ft_printf("%6lc ", 176));
	if (nb == count++)
		return(ac == 2 ? printf("%6lc ", 35211) : ft_printf("%6lc ", 35211));
	if (nb == count++)
		return(ac == 2 ? printf("%6lc ", 128519) : ft_printf("%6lc ", 128519));
	if (nb == count++)
		return(ac == 2 ? printf("%-6lc ", 176) : ft_printf("%-6lc ", 176));
	if (nb == count++)
		return(ac == 2 ? printf("%-6lc ", 35211) : ft_printf("%-6lc ", 35211));
	if (nb == count++)
		return(ac == 2 ? printf("%-6lc ", 128519) : ft_printf("%-6lc ", 128519));
	wchar_t	t[4];
	t[0] = 65;
	t[1] = 0xBF;
	t[2] = 128519;
	t[3] = 0;
	if (nb == count++)
		return(ac == 2 ? printf("%.0ls ", t) : ft_printf("%.0ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%.1ls ", t) : ft_printf("%.1ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%.2ls ", t) : ft_printf("%.2ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%.3ls ", t) : ft_printf("%.3ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%.4ls ", t) : ft_printf("%.4ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%.5ls ", t) : ft_printf("%.5ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%.6ls ", t) : ft_printf("%.6ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%.7ls ", t) : ft_printf("%.7ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.0ls ", t) : ft_printf("%15.0ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.1ls ", t) : ft_printf("%15.1ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.2ls ", t) : ft_printf("%15.2ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.3ls ", t) : ft_printf("%15.3ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.4ls ", t) : ft_printf("%15.4ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.5ls ", t) : ft_printf("%15.5ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.6ls ", t) : ft_printf("%15.6ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15.7ls ", t) : ft_printf("%15.7ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.0ls ", t) : ft_printf("%-15.0ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.1ls ", t) : ft_printf("%-15.1ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.2ls ", t) : ft_printf("%-15.2ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.3ls ", t) : ft_printf("%-15.3ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.4ls ", t) : ft_printf("%-15.4ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.5ls ", t) : ft_printf("%-15.5ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.6ls ", t) : ft_printf("%-15.6ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-15.7ls ", t) : ft_printf("%-15.7ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%ls ", t) : ft_printf("%ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%-ls ", t) : ft_printf("%-ls ", t));
	if (nb == count++)
		return(ac == 2 ? printf("%15ls ", t) : ft_printf("%15ls ", t));

	// [P - Tests with #].
	if (nb == count++)
		return(ac == 2 ? printf("%#x", 42) : ft_printf("%#x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#10x", 42) : ft_printf("%#10x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#-10x", 42) : ft_printf("%#-10x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#010x", 42) : ft_printf("%#010x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#10.4x", 42) : ft_printf("%#10.4x", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#10x", 0) : ft_printf("%#10x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%#10.0x", 0) : ft_printf("%#10.0x", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%#X", 42) : ft_printf("%#X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#10X", 42) : ft_printf("%#10X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#-10X", 42) : ft_printf("%#-10X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#010X", 42) : ft_printf("%#010X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#10.4X", 42) : ft_printf("%#10.4X", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%#10X", 0) : ft_printf("%#10X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%#10.0X", 0) : ft_printf("%#10.0X", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%#f", 42.0) : ft_printf("%#f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0f", 42.0) : ft_printf("%#.0f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0f", -42.0) : ft_printf("%#.0f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0f", 0.0) : ft_printf("%#.0f", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#5.0f", 42.0) : ft_printf("%#5.0f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#-5.0f", -42.0) : ft_printf("%#-5.0f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#-5.0f", 0.0) : ft_printf("%#-5.0f", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#05.0f", 42.0) : ft_printf("%#05.0f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#05.0f", -42.0) : ft_printf("%#05.0f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#05.0f", 0.0) : ft_printf("%#05.0f", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#e", 42.0) : ft_printf("%#e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0e", 42.0) : ft_printf("%#.0e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0e", -42.0) : ft_printf("%#.0e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0e", 0.0) : ft_printf("%#.0e", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#10.0e", 42.0) : ft_printf("%#10.0e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#-10.0e", -42.0) : ft_printf("%#-10.0e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#-10.0e", 0.0) : ft_printf("%#-10.0e", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#010.0e", 42.0) : ft_printf("%#010.0e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#010.0e", -42.0) : ft_printf("%#010.0e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#010.0e", 0.0) : ft_printf("%#010.0e", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#g", 42.0) : ft_printf("%#g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0g", 42.0) : ft_printf("%#.0g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0g", -42.0) : ft_printf("%#.0g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#.0g", 0.0) : ft_printf("%#.0g", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#10.0g", 42.0) : ft_printf("%#10.0g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#-10.0g", -42.0) : ft_printf("%#-10.0g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#-10.0g", 0.0) : ft_printf("%#-10.0g", 0.0));;
	if (nb == count++)
		return(ac == 2 ? printf("%#010.0g", 42.0) : ft_printf("%#010.0g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#010.0g", -42.0) : ft_printf("%#010.0g", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#010.0g", 0.0) : ft_printf("%#010.0g", 0.0));;

	// [R - Tests with plus flag].
	if (nb == count++)
		return(ac == 2 ? printf("%+i", 42) : ft_printf("%+i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%+i", -42) : ft_printf("%+i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%0 10i", 42) : ft_printf("%0 10i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0 10i", -42) : ft_printf("%0 10i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%+5i", 42) : ft_printf("%+5i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%+3i", 42) : ft_printf("%+3i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%+.1i", 0) : ft_printf("%+.1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%+.0i", 0) : ft_printf("%+.0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%+f", 42.0) : ft_printf("%+f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+f", -42.0) : ft_printf("%+f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+10f", 42.0) : ft_printf("%+10f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+f", 0.0) : ft_printf("%+f", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10f", 0.0) : ft_printf("%-+10f", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+15f", 0.0) : ft_printf("%+15f", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+e", 42.0) : ft_printf("%+e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+e", -42.0) : ft_printf("%+e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+10e", 42.0) : ft_printf("%+10e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+e", 0.0) : ft_printf("%+e", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10e", 0.0) : ft_printf("%-+10e", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10e", 42.0) : ft_printf("%-+10e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10e", -42.0) : ft_printf("%-+10e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+23e", 100000.0) : ft_printf("%+23e", 100000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-+23e", 100000.0) : ft_printf("%-+23e", 100000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%+g", 0.00001) : ft_printf("%+g", 0.00001));
	if (nb == count++)
		return(ac == 2 ? printf("%+g", 0.000042) : ft_printf("%+g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%+g", -0.000042) : ft_printf("%+g", -0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%+10g", 0.000042) : ft_printf("%+10g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10g", 0.000042) : ft_printf("%-+10g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%+10g", -0.000042) : ft_printf("%+10g", -0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10g", -0.000042) : ft_printf("%-+10g", -0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%+7g", 0.000042) : ft_printf("%+7g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%-+7g", 0.000042) : ft_printf("%-+7g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%+.2g", 121.42) : ft_printf("%+.2g", 121.42));
	if (nb == count++)
		return(ac == 2 ? printf("%0 10.2g", 121.42) : ft_printf("%0 10.2g", 121.42));
	if (nb == count++)
		return(ac == 2 ? printf("%+g", 0.0001) : ft_printf("%+g", 0.0001));
	if (nb == count++)
		return(ac == 2 ? printf("%+g", 0.00042) : ft_printf("%+g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%+g", -0.00042) : ft_printf("%+g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%+10g", 0.00042) : ft_printf("%+10g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10g", 0.00042) : ft_printf("%-+10g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%+10g", -0.00042) : ft_printf("%+10g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-+10g", -0.00042) : ft_printf("%-+10g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%+7g", 0.00042) : ft_printf("%+7g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-+7g", 0.00042) : ft_printf("%-+7g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%-+7g", 42.0) : ft_printf("%-+7g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#-+7.2g", 42.0) : ft_printf("%#-+7.2g", 42.0));

	// [Q - Tests with space flag].
	if (nb == count++)
		return(ac == 2 ? printf("% i", 42) : ft_printf("% i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("% i", -42) : ft_printf("% i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("%0 10i", 42) : ft_printf("%0 10i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("%0 10i", -42) : ft_printf("%0 10i", -42));
	if (nb == count++)
		return(ac == 2 ? printf("% 5i", 42) : ft_printf("% 5i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("% 3i", 42) : ft_printf("% 3i", 42));
	if (nb == count++)
		return(ac == 2 ? printf("% .1i", 0) : ft_printf("% .1i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("% .0i", 0) : ft_printf("% .0i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("% f", 42.0) : ft_printf("% f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("% f", -42.0) : ft_printf("% f", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("% 10f", 42.0) : ft_printf("% 10f", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("% f", 0.0) : ft_printf("% f", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10f", 0.0) : ft_printf("%- 10f", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("% 15f", 0.0) : ft_printf("% 15f", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("% e", 42.0) : ft_printf("% e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("% e", -42.0) : ft_printf("% e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("% 10e", 42.0) : ft_printf("% 10e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("% e", 0.0) : ft_printf("% e", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10e", 0.0) : ft_printf("%- 10e", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10e", 42.0) : ft_printf("%- 10e", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10e", -42.0) : ft_printf("%- 10e", -42.0));
	if (nb == count++)
		return(ac == 2 ? printf("% 23e", 100000.0) : ft_printf("% 23e", 100000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%- 23e", 100000.0) : ft_printf("%- 23e", 100000.0));
	if (nb == count++)
		return(ac == 2 ? printf("% g", 0.00001) : ft_printf("% g", 0.00001));
	if (nb == count++)
		return(ac == 2 ? printf("% g", 0.000042) : ft_printf("% g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("% g", -0.000042) : ft_printf("% g", -0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("% 10g", 0.000042) : ft_printf("% 10g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10g", 0.000042) : ft_printf("%- 10g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("% 10g", -0.000042) : ft_printf("% 10g", -0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10g", -0.000042) : ft_printf("%- 10g", -0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("% 7g", 0.000042) : ft_printf("% 7g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("%- 7g", 0.000042) : ft_printf("%- 7g", 0.000042));
	if (nb == count++)
		return(ac == 2 ? printf("% .2g", 121.42) : ft_printf("% .2g", 121.42));
	if (nb == count++)
		return(ac == 2 ? printf("%0 10.2g", 121.42) : ft_printf("%0 10.2g", 121.42));
	if (nb == count++)
		return(ac == 2 ? printf("% g", 0.0001) : ft_printf("% g", 0.0001));
	if (nb == count++)
		return(ac == 2 ? printf("% g", 0.00042) : ft_printf("% g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("% g", -0.00042) : ft_printf("% g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("% 10g", 0.00042) : ft_printf("% 10g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10g", 0.00042) : ft_printf("%- 10g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("% 10g", -0.00042) : ft_printf("% 10g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%- 10g", -0.00042) : ft_printf("%- 10g", -0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("% 7g", 0.00042) : ft_printf("% 7g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%- 7g", 0.00042) : ft_printf("%- 7g", 0.00042));
	if (nb == count++)
		return(ac == 2 ? printf("%- 7g", 42.0) : ft_printf("%- 7g", 42.0));
	if (nb == count++)
		return(ac == 2 ? printf("%#- 7.2g", 42.0) : ft_printf("%#- 7.2g", 42.0));

	// [S - Tests with ' flag].
	setlocale(LC_ALL, "en_US");
	if (nb == count++)
		return(ac == 2 ? printf("%'i", 10000) : ft_printf("%'i", 10000));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", 0) : ft_printf("%'i", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", 999) : ft_printf("%'i", 999));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", 1000) : ft_printf("%'i", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", 789456) : ft_printf("%'i", 789456));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", 1000000) : ft_printf("%'i", 1000000));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", 999000000) : ft_printf("%'i", 999000000));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", -10000) : ft_printf("%'i", -10000));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", -999) : ft_printf("%'i", -999));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", -1000) : ft_printf("%'i", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%'i", -789456) : ft_printf("%'i", -789456));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", 10000) : ft_printf("%'u", 10000));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", 0) : ft_printf("%'u", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", 999) : ft_printf("%'u", 999));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", 1000) : ft_printf("%'u", 1000));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", 789456) : ft_printf("%'u", 789456));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", 1000000) : ft_printf("%'u", 1000000));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", 999000000) : ft_printf("%'u", 999000000));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", -10000) : ft_printf("%'u", -10000));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", -999) : ft_printf("%'u", -999));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", -1000) : ft_printf("%'u", -1000));
	if (nb == count++)
		return(ac == 2 ? printf("%'u", -789456) : ft_printf("%'u", -789456));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 10000.0) : ft_printf("%'f", 10000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 0.0) : ft_printf("%'f", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 999.0) : ft_printf("%'f", 999.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 1000.0) : ft_printf("%'f", 1000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 789456.0) : ft_printf("%'f", 789456.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 1000000.0) : ft_printf("%'f", 1000000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 999000000.0) : ft_printf("%'f", 999000000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", -10000.0) : ft_printf("%'f", -10000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", -999.0) : ft_printf("%'f", -999.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", -1000.0) : ft_printf("%'f", -1000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", -789456.0) : ft_printf("%'f", -789456.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 10000.0) : ft_printf("%'g", 10000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 0.0) : ft_printf("%'g", 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 999.0) : ft_printf("%'g", 999.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 1000.0) : ft_printf("%'g", 1000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 789456.0) : ft_printf("%'g", 789456.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'.10g", 1000000.0) : ft_printf("%'.10g", 1000000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'.15g", 999000000.0) : ft_printf("%'.15g", 999000000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", -10000.0) : ft_printf("%'g", -10000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", -999.0) : ft_printf("%'g", -999.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", -1000.0) : ft_printf("%'g", -1000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", -789456.0) : ft_printf("%'g", -789456.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 10000.0) : ft_printf("%'g", 10000.0));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 0.42) : ft_printf("%'f", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%'f", 0.0001) : ft_printf("%'f", 0.0001));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 0.42) : ft_printf("%'g", 0.42));
	if (nb == count++)
		return(ac == 2 ? printf("%'g", 0.001) : ft_printf("%'g", 0.001));

	// [T - Tests with infinity and nan].
	if (nb == count++)
		return(ac == 2 ? printf("%-10g", 0.0 / 0.0) : ft_printf("%-10g", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010g", 0.0 / 0.0) : ft_printf("%010g", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10g", 0.0 / 0.0) : ft_printf("%10g", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10e", 0.0 / 0.0) : ft_printf("%-10e", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010e", 0.0 / 0.0) : ft_printf("%010e", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10e", 0.0 / 0.0) : ft_printf("%10e", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10f", 0.0 / 0.0) : ft_printf("%-10f", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010f", 0.0 / 0.0) : ft_printf("%010f", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10f", 0.0 / 0.0) : ft_printf("%10f", 0.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10g", -1.0 / 0.0) : ft_printf("%-10g", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010g", -1.0 / 0.0) : ft_printf("%010g", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10g", -1.0 / 0.0) : ft_printf("%10g", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10e", -1.0 / 0.0) : ft_printf("%-10e", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010e", -1.0 / 0.0) : ft_printf("%010e", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10e", -1.0 / 0.0) : ft_printf("%10e", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10f", -1.0 / 0.0) : ft_printf("%-10f", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010f", -1.0 / 0.0) : ft_printf("%010f", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10f", -1.0 / 0.0) : ft_printf("%10f", -1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10g", 1.0 / 0.0) : ft_printf("%-10g", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010g", 1.0 / 0.0) : ft_printf("%010g", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10g", 1.0 / 0.0) : ft_printf("%10g", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10e", 1.0 / 0.0) : ft_printf("%-10e", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010e", 1.0 / 0.0) : ft_printf("%010e", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10e", 1.0 / 0.0) : ft_printf("%10e", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%-10f", 1.0 / 0.0) : ft_printf("%-10f", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%010f", 1.0 / 0.0) : ft_printf("%010f", 1.0 / 0.0));
	if (nb == count++)
		return(ac == 2 ? printf("%10f", 1.0 / 0.0) : ft_printf("%10f", 1.0 / 0.0));

	// [U - Tests with o (our bonus !)].
	if (nb == count++)
		return(ac == 2 ? printf("%o", 042) : ft_printf("%o", 042));
	if (nb == count++)
		return(ac == 2 ? printf("%o", 0) : ft_printf("%o", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%o", 8) : ft_printf("%o", 8));
	if (nb == count++)
		return(ac == 2 ? printf("%10o", 042) : ft_printf("%10o", 042));
	if (nb == count++)
		return(ac == 2 ? printf("%.2o", 456789) : ft_printf("%.2o", 456789));
	if (nb == count++)
		return(ac == 2 ? printf("%-10.3o", 456789) : ft_printf("%-10.3o", 456789));
	if (nb == count++)
		return(ac == 2 ? printf("%#-10o", 042) : ft_printf("%#-10o", 042));
	if (nb == count++)
		return(ac == 2 ? printf("%#010o", 042) : ft_printf("%#010o", 042));
	if (nb == count++)
		return(ac == 2 ? printf("%'o", 123456789) : ft_printf("%'o", 123456789));
	if (nb == count++)
		return(ac == 2 ? printf("%#1.o", 0) : ft_printf("%#1.o", 0));
	if (nb == count++)
		return(ac == 2 ? printf("%#o", 0) : ft_printf("%#o", 0));
	if (nb == count++)
		return(ac == 2 ? printf("|%#01o| |%#0.10o| |%#010o| |%#0-10o| |%#0+10o| |%#0+10.o| |%#0-10.o|\n", 0, 0, 0, 0, 0, 0, 0) : ft_printf("|%#01o| |%#0.10o| |%#010o| |%#0-10o| |%#0+10o| |%#0+10.o| |%#0-10.o|\n", 0, 0, 0, 0, 0, 0, 0));
	if (nb == count++)
		return(ac == 2 ? printf("|%#01.o| |%02.o| |%-03.o| |%1.o| |%2.o| |%-.1o| |%-.2o|\n", 0, 0, 0, 0, 0, 0, 0) : ft_printf("|%#01.o| |%02.o| |%-03.o| |%1.o| |%2.o| |%-.1o| |%-.2o|\n", 0, 0, 0, 0, 0, 0, 0));
	unsigned int nbr = 4578;
	if (nb == count++)
		return(ac == 2 ? printf("|%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.8o| : %%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.8o\n", nbr) : ft_printf("|%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.8o| : %%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.8o\n", nbr));
	if (nb == count++)
		return(ac == 2 ? printf("|%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.6o| : %%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.6o\n", nbr) : ft_printf("|%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.6o| : %%+- +-0#+ -0 +0 -+ +0+ -+-+# 0+0-0+0-#0+ 0+ 15.6o\n", nbr));
	if (nb == count++)
		return(ac == 2 ? printf("|%+- #0 - 0 + -0# - + - 0-+ - #+- 7o| : %%+- #0 - 0 + -0# - + - 0-+ - #+- 7o\n", nbr) : ft_printf("|%+- #0 - 0 + -0# - + - 0-+ - #+- 7o| : %%+- #0 - 0 + -0# - + - 0-+ - #+- 7o\n", nbr));

	// [Z - MIX (good test for leaks)].
	int		z;
	wchar_t	y[10];
	y[0] = 65;
	y[1] = 0xBF;
	y[2] = 128519;
	y[3] = 32;
	y[4] = 0;
	setlocale(LC_ALL, "en_US");
	if (nb == count++)
		return(ac == 2 ? printf("012%c3456%s789%%012%i3456%x789%u012%p456789%e012%f3456789%g0123456789%o01%lc3456%ls789%n012%c3456%s789%%012%i3456%x789%u012%p456789%e012%f3456789%g0123456789%o01%lc3456%ls789%n", 'A', "TEST", 42, 0x42, 42, (void*)42, 4.2, -4.2, 4.101, 042, 35211, y, &z, 'A', "TEST", -21, -0x21, 0, (void*)0x101, 4.2, -4.2, 4.101, 042, 35211, y, &z) : ft_printf("012%c3456%s789%%012%i3456%x789%u012%p456789%e012%f3456789%g0123456789%o01%lc3456%ls789%n012%c3456%s789%%012%i3456%x789%u012%p456789%e012%f3456789%g0123456789%o01%lc3456%ls789%n", 'A', "TEST", 42, 0x42, 42, (void*)42, 4.2, -4.2, 4.101, 042, 35211, y, &z, 'A', "TEST", -21, -0x21, 0, (void*)0x101, 4.2, -4.2, 4.101, 042, 35211, y, &z));

	// [End].
	return (0);
}
