/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 17:50:35 by jgambard    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../ft_printf.h"
#include <limits.h>

typedef int		(*t_fct)(const char *s, ...);

t_fct	get_fct(int ac)
{
	if (ac == 2)
		return (printf);
	else
		return (ft_printf);
}

int		main(int ac, char **av)
{
	t_fct	fct;
	int		nb;
	int		count;

	fct = get_fct(ac);
	nb = atoi(av[1]);
	count = 0;

	// [Tests without options]
	if (nb == count++)
		fct("");
	else if (nb == count++)
		fct("Hello");
	else if (nb == count++)
		fct("Hello%");
	else if (nb == count++)
		fct("1");
	else if (nb == count++)
		fct("1%");
	else if (nb == count++)
		fct("%");
	else if (nb == count++)
		fct("%%");
	else if (nb == count++)
		fct("%%%");
	else if (nb == count++)
		fct("%%%%");
	else if (nb == count++)
		fct("%c", '1');
	else if (nb == count++)
		fct("%c%", '2');
	else if (nb == count++)
		fct("%c%%", '3');
	else if (nb == count++)
		fct("0%c", 0);
	else if (nb == count++)
		fct("%c", -129);
	else if (nb == count++)
		fct("%c", 128);
	else if (nb == count++)
		fct("%s", "Hello");
	else if (nb == count++)
		fct("%s%", "Hello2");
	else if (nb == count++)
		fct("%s%%", "Hello3");
	else if (nb == count++)
		fct("%s", "");
	else if (nb == count++)
		fct("%s%", "");
	else if (nb == count++)
		fct("%s", NULL);
	else if (nb == count++)
		fct("%s%", NULL);
	else if (nb == count++)
		fct("%s", "1");
	else if (nb == count++)
		fct("%i", 0);
	else if (nb == count++)
		fct("%i", -1);
	else if (nb == count++)
		fct("%i", -42);
	else if (nb == count++)
		fct("%i", 1);
	else if (nb == count++)
		fct("%i", 42);
	else if (nb == count++)
		fct("%i", INT_MAX);
	else if (nb == count++)
		fct("%i", INT_MAX + 1);
	else if (nb == count++)
		fct("%i", INT_MIN);
	else if (nb == count++)
		fct("%i", 1000);
	else if (nb == count++)
		fct("%i", -1000);
	else if (nb == count++)
		fct("%d", 0);
	else if (nb == count++)
		fct("%d", -1);
	else if (nb == count++)
		fct("%d", -42);
	else if (nb == count++)
		fct("%d", 1);
	else if (nb == count++)
		fct("%d", 42);
	else if (nb == count++)
		fct("%d", INT_MAX);
	else if (nb == count++)
		fct("%d", INT_MAX + 1);
	else if (nb == count++)
		fct("%d", INT_MIN);
	else if (nb == count++)
		fct("%d", 1000);
	else if (nb == count++)
		fct("%d", -1000);
	else if (nb == count++)
		fct("%u", 0);
	else if (nb == count++)
		fct("%u", -1);
	else if (nb == count++)
		fct("%u", 1);
	else if (nb == count++)
		fct("%u", 42);
	else if (nb == count++)
		fct("%u", UINT_MAX);
	else if (nb == count++)
		fct("%u", UINT_MAX + 1);
	else if (nb == count++)
		fct("%u", 1000);
	else if (nb == count++)
		fct("%x", 0);
	else if (nb == count++)
		fct("%x", -1);
	else if (nb == count++)
		fct("%x", -42);
	else if (nb == count++)
		fct("%x", 1);
	else if (nb == count++)
		fct("%x", 42);
	else if (nb == count++)
		fct("%x", INT_MAX);
	else if (nb == count++)
		fct("%x", INT_MAX + 1);
	else if (nb == count++)
		fct("%x", INT_MIN);
	else if (nb == count++)
		fct("%x", 1000);
	else if (nb == count++)
		fct("%x", -1000);
	else if (nb == count++)
		fct("%X", 0);
	else if (nb == count++)
		fct("%X", -1);
	else if (nb == count++)
		fct("%X", -42);
	else if (nb == count++)
		fct("%X", 1);
	else if (nb == count++)
		fct("%X", 42);
	else if (nb == count++)
		fct("%X", INT_MAX);
	else if (nb == count++)
		fct("%X", INT_MAX + 1);
	else if (nb == count++)
		fct("%X", INT_MIN);
	else if (nb == count++)
		fct("%X", 1000);
	else if (nb == count++)
		fct("%X", -1000);
	else if (nb == count++)
		fct("%p", NULL);
	else if (nb == count++)
		fct("%p", (void*)1);
	else if (nb == count++)
		fct("%p", (void*)-1);
	else if (nb == count++)
		fct("%p", (void*)42);
	else if (nb == count++)
		fct("%p", (void*)1000);
	else if (nb == count++)
		fct("%p", (void*)ULONG_MAX);
	else if (nb == count++)
		fct("%p", (void*)ULONG_MAX + 1);

	// [Tests with minimum field width]
	else if (nb == count++)
		fct("%1%");
	else if (nb == count++)
		fct("%2%");
	else if (nb == count++)
		fct("%10%");
	else if (nb == count++)
		fct("%1c", '1');
	else if (nb == count++)
		fct("%2c", '1');
	else if (nb == count++)
		fct("%10c", '1');
	else if (nb == count++)
		fct("%6s", NULL);
	else if (nb == count++)
		fct("%7s", NULL);
	else if (nb == count++)
		fct("%1s", "");
	else if (nb == count++)
		fct("%5s", "Hello");
	else if (nb == count++)
		fct("%6s", "Hello");
	else if (nb == count++)
		fct("%1i", 0);
	else if (nb == count++)
		fct("%2i", 0);
	else if (nb == count++)
		fct("%10i", 0);
	else if (nb == count++)
		fct("%1i", -1);
	else if (nb == count++)
		fct("%2i", -1);
	else if (nb == count++)
		fct("%3i", -1);
	else if (nb == count++)
		fct("%9i", INT_MAX);
	else if (nb == count++)
		fct("%10i", INT_MAX);
	else if (nb == count++)
		fct("%11i", INT_MAX);
	else if (nb == count++)
		fct("%1d", 0);
	else if (nb == count++)
		fct("%2d", 0);
	else if (nb == count++)
		fct("%10d", 0);
	else if (nb == count++)
		fct("%1d", -1);
	else if (nb == count++)
		fct("%2d", -1);
	else if (nb == count++)
		fct("%3d", -1);
	else if (nb == count++)
		fct("%9d", INT_MAX);
	else if (nb == count++)
		fct("%10d", INT_MAX);
	else if (nb == count++)
		fct("%11d", INT_MAX);
	else if (nb == count++)
		fct("%1u", 0);
	else if (nb == count++)
		fct("%2u", 0);
	else if (nb == count++)
		fct("%10u", 0);
	else if (nb == count++)
		fct("%1u", -1);
	else if (nb == count++)
		fct("%2u", -1);
	else if (nb == count++)
		fct("%3u", -1);
	else if (nb == count++)
		fct("%9u", UINT_MAX);
	else if (nb == count++)
		fct("%10u", UINT_MAX);
	else if (nb == count++)
		fct("%11u", UINT_MAX);
	else if (nb == count++)
		fct("%1x", 0);
	else if (nb == count++)
		fct("%2x", 0);
	else if (nb == count++)
		fct("%10x", 0);
	else if (nb == count++)
		fct("%1x", -1);
	else if (nb == count++)
		fct("%2x", -1);
	else if (nb == count++)
		fct("%3x", -1);
	else if (nb == count++)
		fct("%9x", UINT_MAX);
	else if (nb == count++)
		fct("%10x", UINT_MAX);
	else if (nb == count++)
		fct("%11x", UINT_MAX);
	else if (nb == count++)
		fct("%1X", 0);
	else if (nb == count++)
		fct("%2X", 0);
	else if (nb == count++)
		fct("%10X", 0);
	else if (nb == count++)
		fct("%1X", -1);
	else if (nb == count++)
		fct("%2X", -1);
	else if (nb == count++)
		fct("%3X", -1);
	else if (nb == count++)
		fct("%9X", UINT_MAX);
	else if (nb == count++)
		fct("%10X", UINT_MAX);
	else if (nb == count++)
		fct("%11X", UINT_MAX);
	else if (nb == count++)
		fct("%6p", NULL);
	else if (nb == count++)
		fct("%7p", NULL);
	else if (nb == count++)
		fct("%1p", (void*)42);
	else if (nb == count++)
		fct("%5p", (void*)42);

	// [Tests with flag -]
	else if (nb == count++)
		fct("%-1%");
	else if (nb == count++)
		fct("%-2%");
	else if (nb == count++)
		fct("%-10%");
	else if (nb == count++)
		fct("%-1c", '1');
	else if (nb == count++)
		fct("%-2c", '1');
	else if (nb == count++)
		fct("%-10c", '1');
	else if (nb == count++)
		fct("%-6s", NULL);
	else if (nb == count++)
		fct("%-7s", NULL);
	else if (nb == count++)
		fct("%-1s", "");
	else if (nb == count++)
		fct("%-5s", "Hello");
	else if (nb == count++)
		fct("%-6s", "Hello");
	else if (nb == count++)
		fct("%-1i", 0);
	else if (nb == count++)
		fct("%-2i", 0);
	else if (nb == count++)
		fct("%-10i", 0);
	else if (nb == count++)
		fct("%-1i", -1);
	else if (nb == count++)
		fct("%-2i", -1);
	else if (nb == count++)
		fct("%-3i", -1);
	else if (nb == count++)
		fct("%-9i", INT_MAX);
	else if (nb == count++)
		fct("%-10i", INT_MAX);
	else if (nb == count++)
		fct("%-11i", INT_MAX);
	else if (nb == count++)
		fct("%-1d", 0);
	else if (nb == count++)
		fct("%-2d", 0);
	else if (nb == count++)
		fct("%-10d", 0);
	else if (nb == count++)
		fct("%-1d", -1);
	else if (nb == count++)
		fct("%-2d", -1);
	else if (nb == count++)
		fct("%-3d", -1);
	else if (nb == count++)
		fct("%-9d", INT_MAX);
	else if (nb == count++)
		fct("%-10d", INT_MAX);
	else if (nb == count++)
		fct("%-11d", INT_MAX);
	else if (nb == count++)
		fct("%-1u", 0);
	else if (nb == count++)
		fct("%-2u", 0);
	else if (nb == count++)
		fct("%-10u", 0);
	else if (nb == count++)
		fct("%-1u", -1);
	else if (nb == count++)
		fct("%-2u", -1);
	else if (nb == count++)
		fct("%-3u", -1);
	else if (nb == count++)
		fct("%-9u", UINT_MAX);
	else if (nb == count++)
		fct("%-10u", UINT_MAX);
	else if (nb == count++)
		fct("%-11u", UINT_MAX);
	else if (nb == count++)
		fct("%-1x", 0);
	else if (nb == count++)
		fct("%-2x", 0);
	else if (nb == count++)
		fct("%-10x", 0);
	else if (nb == count++)
		fct("%-1x", -1);
	else if (nb == count++)
		fct("%-2x", -1);
	else if (nb == count++)
		fct("%-3x", -1);
	else if (nb == count++)
		fct("%-9x", UINT_MAX);
	else if (nb == count++)
		fct("%-10x", UINT_MAX);
	else if (nb == count++)
		fct("%-11x", UINT_MAX);
	else if (nb == count++)
		fct("%-1X", 0);
	else if (nb == count++)
		fct("%-2X", 0);
	else if (nb == count++)
		fct("%-10X", 0);
	else if (nb == count++)
		fct("%-1X", -1);
	else if (nb == count++)
		fct("%-2X", -1);
	else if (nb == count++)
		fct("%-3X", -1);
	else if (nb == count++)
		fct("%-9X", UINT_MAX);
	else if (nb == count++)
		fct("%-10X", UINT_MAX);
	else if (nb == count++)
		fct("%-11X", UINT_MAX);
	else if (nb == count++)
		fct("%-6p", NULL);
	else if (nb == count++)
		fct("%-7p", NULL);
	else if (nb == count++)
		fct("%-1p", (void*)42);
	else if (nb == count++)
		fct("%-5p", (void*)42);

	// [Tests with flag 0]
	else if (nb == count++)
		fct("%01%");
	else if (nb == count++)
		fct("%02%");
	else if (nb == count++)
		fct("%010%");
	else if (nb == count++)
		fct("%01c", '1');
	else if (nb == count++)
		fct("%02c", '1');
	else if (nb == count++)
		fct("%010c", '1');
	else if (nb == count++)
		fct("%06s", NULL);
	else if (nb == count++)
		fct("%07s", NULL);
	else if (nb == count++)
		fct("%01s", "");
	else if (nb == count++)
		fct("%05s", "Hello");
	else if (nb == count++)
		fct("%06s", "Hello");
	else if (nb == count++)
		fct("%01i", 0);
	else if (nb == count++)
		fct("%02i", 0);
	else if (nb == count++)
		fct("%010i", 0);
	else if (nb == count++)
		fct("%01i", -1);
	else if (nb == count++)
		fct("%02i", -1);
	else if (nb == count++)
		fct("%03i", -1);
	else if (nb == count++)
		fct("%09i", INT_MAX);
	else if (nb == count++)
		fct("%010i", INT_MAX);
	else if (nb == count++)
		fct("%011i", INT_MAX);
	else if (nb == count++)
		fct("%01d", 0);
	else if (nb == count++)
		fct("%02d", 0);
	else if (nb == count++)
		fct("%010d", 0);
	else if (nb == count++)
		fct("%01d", -1);
	else if (nb == count++)
		fct("%02d", -1);
	else if (nb == count++)
		fct("%03d", -1);
	else if (nb == count++)
		fct("%09d", INT_MAX);
	else if (nb == count++)
		fct("%010d", INT_MAX);
	else if (nb == count++)
		fct("%011d", INT_MAX);
	else if (nb == count++)
		fct("%01u", 0);
	else if (nb == count++)
		fct("%02u", 0);
	else if (nb == count++)
		fct("%010u", 0);
	else if (nb == count++)
		fct("%01u", -1);
	else if (nb == count++)
		fct("%02u", -1);
	else if (nb == count++)
		fct("%03u", -1);
	else if (nb == count++)
		fct("%09u", UINT_MAX);
	else if (nb == count++)
		fct("%010u", UINT_MAX);
	else if (nb == count++)
		fct("%011u", UINT_MAX);
	else if (nb == count++)
		fct("%01x", 0);
	else if (nb == count++)
		fct("%02x", 0);
	else if (nb == count++)
		fct("%010x", 0);
	else if (nb == count++)
		fct("%01x", -1);
	else if (nb == count++)
		fct("%02x", -1);
	else if (nb == count++)
		fct("%03x", -1);
	else if (nb == count++)
		fct("%09x", UINT_MAX);
	else if (nb == count++)
		fct("%010x", UINT_MAX);
	else if (nb == count++)
		fct("%011x", UINT_MAX);
	else if (nb == count++)
		fct("%01X", 0);
	else if (nb == count++)
		fct("%02X", 0);
	else if (nb == count++)
		fct("%010X", 0);
	else if (nb == count++)
		fct("%01X", -1);
	else if (nb == count++)
		fct("%02X", -1);
	else if (nb == count++)
		fct("%03X", -1);
	else if (nb == count++)
		fct("%09X", UINT_MAX);
	else if (nb == count++)
		fct("%010X", UINT_MAX);
	else if (nb == count++)
		fct("%011X", UINT_MAX);
	else if (nb == count++)
		fct("%06p", NULL);
	else if (nb == count++)
		fct("%07p", NULL);
	else if (nb == count++)
		fct("%01p", (void*)42);
	else if (nb == count++)
		fct("%05p", (void*)42);

	// [Tests with flags 0-]
	else if (nb == count++)
		fct("%0-1%");
	else if (nb == count++)
		fct("%0-2%");
	else if (nb == count++)
		fct("%0-10%");
	else if (nb == count++)
		fct("%0-1c", '1');
	else if (nb == count++)
		fct("%0-2c", '1');
	else if (nb == count++)
		fct("%0-10c", '1');
	else if (nb == count++)
		fct("%0-6s", NULL);
	else if (nb == count++)
		fct("%0-7s", NULL);
	else if (nb == count++)
		fct("%0-1s", "");
	else if (nb == count++)
		fct("%0-5s", "Hello");
	else if (nb == count++)
		fct("%0-6s", "Hello");
	else if (nb == count++)
		fct("%0-1i", 0);
	else if (nb == count++)
		fct("%0-2i", 0);
	else if (nb == count++)
		fct("%0-10i", 0);
	else if (nb == count++)
		fct("%0-1i", -1);
	else if (nb == count++)
		fct("%0-2i", -1);
	else if (nb == count++)
		fct("%0-3i", -1);
	else if (nb == count++)
		fct("%0-9i", INT_MAX);
	else if (nb == count++)
		fct("%0-10i", INT_MAX);
	else if (nb == count++)
		fct("%0-11i", INT_MAX);
	else if (nb == count++)
		fct("%0-1d", 0);
	else if (nb == count++)
		fct("%0-2d", 0);
	else if (nb == count++)
		fct("%0-10d", 0);
	else if (nb == count++)
		fct("%0-1d", -1);
	else if (nb == count++)
		fct("%0-2d", -1);
	else if (nb == count++)
		fct("%0-3d", -1);
	else if (nb == count++)
		fct("%0-9d", INT_MAX);
	else if (nb == count++)
		fct("%0-10d", INT_MAX);
	else if (nb == count++)
		fct("%0-11d", INT_MAX);
	else if (nb == count++)
		fct("%0-1u", 0);
	else if (nb == count++)
		fct("%0-2u", 0);
	else if (nb == count++)
		fct("%0-10u", 0);
	else if (nb == count++)
		fct("%0-1u", -1);
	else if (nb == count++)
		fct("%0-2u", -1);
	else if (nb == count++)
		fct("%0-3u", -1);
	else if (nb == count++)
		fct("%0-9u", UINT_MAX);
	else if (nb == count++)
		fct("%0-10u", UINT_MAX);
	else if (nb == count++)
		fct("%0-11u", UINT_MAX);
	else if (nb == count++)
		fct("%0-1x", 0);
	else if (nb == count++)
		fct("%0-2x", 0);
	else if (nb == count++)
		fct("%0-10x", 0);
	else if (nb == count++)
		fct("%0-1x", -1);
	else if (nb == count++)
		fct("%0-2x", -1);
	else if (nb == count++)
		fct("%0-3x", -1);
	else if (nb == count++)
		fct("%0-9x", UINT_MAX);
	else if (nb == count++)
		fct("%0-10x", UINT_MAX);
	else if (nb == count++)
		fct("%0-11x", UINT_MAX);
	else if (nb == count++)
		fct("%0-1X", 0);
	else if (nb == count++)
		fct("%0-2X", 0);
	else if (nb == count++)
		fct("%0-10X", 0);
	else if (nb == count++)
		fct("%0-1X", -1);
	else if (nb == count++)
		fct("%0-2X", -1);
	else if (nb == count++)
		fct("%0-3X", -1);
	else if (nb == count++)
		fct("%0-9X", UINT_MAX);
	else if (nb == count++)
		fct("%0-10X", UINT_MAX);
	else if (nb == count++)
		fct("%0-11X", UINT_MAX);
	else if (nb == count++)
		fct("%0-6p", NULL);
	else if (nb == count++)
		fct("%0-7p", NULL);
	else if (nb == count++)
		fct("%0-1p", (void*)42);
	else if (nb == count++)
		fct("%0-5p", (void*)42);

	// [Tests with flags -0]
	else if (nb == count++)
		fct("%-01%");
	else if (nb == count++)
		fct("%-02%");
	else if (nb == count++)
		fct("%-010%");
	else if (nb == count++)
		fct("%-01c", '1');
	else if (nb == count++)
		fct("%-02c", '1');
	else if (nb == count++)
		fct("%-010c", '1');
	else if (nb == count++)
		fct("%-06s", NULL);
	else if (nb == count++)
		fct("%-07s", NULL);
	else if (nb == count++)
		fct("%-01s", "");
	else if (nb == count++)
		fct("%-05s", "Hello");
	else if (nb == count++)
		fct("%-06s", "Hello");
	else if (nb == count++)
		fct("%-01i", 0);
	else if (nb == count++)
		fct("%-02i", 0);
	else if (nb == count++)
		fct("%-010i", 0);
	else if (nb == count++)
		fct("%-01i", -1);
	else if (nb == count++)
		fct("%-02i", -1);
	else if (nb == count++)
		fct("%-03i", -1);
	else if (nb == count++)
		fct("%-09i", INT_MAX);
	else if (nb == count++)
		fct("%-010i", INT_MAX);
	else if (nb == count++)
		fct("%-011i", INT_MAX);
	else if (nb == count++)
		fct("%-01d", 0);
	else if (nb == count++)
		fct("%-02d", 0);
	else if (nb == count++)
		fct("%-010d", 0);
	else if (nb == count++)
		fct("%-01d", -1);
	else if (nb == count++)
		fct("%-02d", -1);
	else if (nb == count++)
		fct("%-03d", -1);
	else if (nb == count++)
		fct("%-09d", INT_MAX);
	else if (nb == count++)
		fct("%-010d", INT_MAX);
	else if (nb == count++)
		fct("%-011d", INT_MAX);
	else if (nb == count++)
		fct("%-01u", 0);
	else if (nb == count++)
		fct("%-02u", 0);
	else if (nb == count++)
		fct("%-010u", 0);
	else if (nb == count++)
		fct("%-01u", -1);
	else if (nb == count++)
		fct("%-02u", -1);
	else if (nb == count++)
		fct("%-03u", -1);
	else if (nb == count++)
		fct("%-09u", UINT_MAX);
	else if (nb == count++)
		fct("%-010u", UINT_MAX);
	else if (nb == count++)
		fct("%-011u", UINT_MAX);
	else if (nb == count++)
		fct("%-01x", 0);
	else if (nb == count++)
		fct("%-02x", 0);
	else if (nb == count++)
		fct("%-010x", 0);
	else if (nb == count++)
		fct("%-01x", -1);
	else if (nb == count++)
		fct("%-02x", -1);
	else if (nb == count++)
		fct("%-03x", -1);
	else if (nb == count++)
		fct("%-09x", UINT_MAX);
	else if (nb == count++)
		fct("%-010x", UINT_MAX);
	else if (nb == count++)
		fct("%-011x", UINT_MAX);
	else if (nb == count++)
		fct("%-01X", 0);
	else if (nb == count++)
		fct("%-02X", 0);
	else if (nb == count++)
		fct("%-010X", 0);
	else if (nb == count++)
		fct("%-01X", -1);
	else if (nb == count++)
		fct("%-02X", -1);
	else if (nb == count++)
		fct("%-03X", -1);
	else if (nb == count++)
		fct("%-09X", UINT_MAX);
	else if (nb == count++)
		fct("%-010X", UINT_MAX);
	else if (nb == count++)
		fct("%-011X", UINT_MAX);
	else if (nb == count++)
		fct("%-06p", NULL);
	else if (nb == count++)
		fct("%-07p", NULL);
	else if (nb == count++)
		fct("%-01p", (void*)42);
	else if (nb == count++)
		fct("%-05p", (void*)42);
	
	// [Tests with .]
	else if (nb == count++)
		fct("%.0%");
	else if (nb == count++)
		fct("%.1%");
	else if (nb == count++)
		fct("%.2%");
	else if (nb == count++)
		fct("%.10%");
	else if (nb == count++)
		fct("%.0c", '1');
	else if (nb == count++)
		fct("%.1c", '1');
	else if (nb == count++)
		fct("%.2c", '1');
	else if (nb == count++)
		fct("%.10c", '1');
	else if (nb == count++)
		fct("%.0s", NULL);
	else if (nb == count++)
		fct("%.1s", NULL);
	else if (nb == count++)
		fct("%.6s", NULL);
	else if (nb == count++)
		fct("%.10s", NULL);
	else if (nb == count++)
		fct("%.0s", "");
	else if (nb == count++)
		fct("%.1s", "");
	else if (nb == count++)
		fct("%.3s", "");
	else if (nb == count++)
		fct("%.0s", "Hello");
	else if (nb == count++)
		fct("%.1s", "Hello");
	else if (nb == count++)
		fct("%.2s", "Hello");
	else if (nb == count++)
		fct("%.5s", "Hello");
	else if (nb == count++)
		fct("%.6s", "Hello");
	else if (nb == count++)
		fct("%.7s", "Hello");
	else if (nb == count++)
		fct("%.0d", 0);
	else if (nb == count++)
		fct("%.1d", 0);
	else if (nb == count++)
		fct("%.2d", 0);
	else if (nb == count++)
		fct("%.0d", 5);
	else if (nb == count++)
		fct("%.1d", 5);
	else if (nb == count++)
		fct("%.2d", 5);
	else if (nb == count++)
		fct("%.0d", 42);
	else if (nb == count++)
		fct("%.1d", 42);
	else if (nb == count++)
		fct("%.2d", 42);
	else if (nb == count++)
		fct("%.3d", 42);
	else if (nb == count++)
		fct("%.10d", 42);
	else if (nb == count++)
		fct("%.6d", 100);
	else if (nb == count++)
		fct("%.0d", -1);
	else if (nb == count++)
		fct("%.1d", -1);
	else if (nb == count++)
		fct("%.2d", -1);
	else if (nb == count++)
		fct("%.3d", -1);
	else if (nb == count++)
		fct("%.0d", -42);
	else if (nb == count++)
		fct("%.1d", -42);
	else if (nb == count++)
		fct("%.3d", -42);
	else if (nb == count++)
		fct("%.4d", -42);
	else if (nb == count++)
		fct("%.20d", INT_MAX);
	else if (nb == count++)
		fct("%.20d", INT_MAX + 1);
	else if (nb == count++)
		fct("%.20d", INT_MIN);
	else if (nb == count++)
		fct("%.20d", INT_MIN - 1);
	else if (nb == count++)
		fct("%.0i", 0);
	else if (nb == count++)
		fct("%.1i", 0);
	else if (nb == count++)
		fct("%.2i", 0);
	else if (nb == count++)
		fct("%.0i", 5);
	else if (nb == count++)
		fct("%.1i", 5);
	else if (nb == count++)
		fct("%.2i", 5);
	else if (nb == count++)
		fct("%.0i", 42);
	else if (nb == count++)
		fct("%.1i", 42);
	else if (nb == count++)
		fct("%.2i", 42);
	else if (nb == count++)
		fct("%.3i", 42);
	else if (nb == count++)
		fct("%.10i", 42);
	else if (nb == count++)
		fct("%.6i", 100);
	else if (nb == count++)
		fct("%.0i", -1);
	else if (nb == count++)
		fct("%.1i", -1);
	else if (nb == count++)
		fct("%.2i", -1);
	else if (nb == count++)
		fct("%.3i", -1);
	else if (nb == count++)
		fct("%.0i", -42);
	else if (nb == count++)
		fct("%.1i", -42);
	else if (nb == count++)
		fct("%.3i", -42);
	else if (nb == count++)
		fct("%.4i", -42);
	else if (nb == count++)
		fct("%.20i", INT_MAX);
	else if (nb == count++)
		fct("%.20i", INT_MAX + 1);
	else if (nb == count++)
		fct("%.20i", INT_MIN);
	else if (nb == count++)
		fct("%.20i", INT_MIN - 1);
	else if (nb == count++)
		fct("%.0u", 0);
	else if (nb == count++)
		fct("%.1u", 0);
	else if (nb == count++)
		fct("%.2u", 0);
	else if (nb == count++)
		fct("%.0u", 5);
	else if (nb == count++)
		fct("%.1u", 5);
	else if (nb == count++)
		fct("%.2u", 5);
	else if (nb == count++)
		fct("%.0u", 42);
	else if (nb == count++)
		fct("%.1u", 42);
	else if (nb == count++)
		fct("%.2u", 42);
	else if (nb == count++)
		fct("%.3u", 42);
	else if (nb == count++)
		fct("%.10u", 42);
	else if (nb == count++)
		fct("%.6u", 100);
	else if (nb == count++)
		fct("%.0u", -1);
	else if (nb == count++)
		fct("%.1u", -1);
	else if (nb == count++)
		fct("%.2u", -1);
	else if (nb == count++)
		fct("%.3u", -1);
	else if (nb == count++)
		fct("%.0u", -42);
	else if (nb == count++)
		fct("%.1u", -42);
	else if (nb == count++)
		fct("%.3u", -42);
	else if (nb == count++)
		fct("%.4u", -42);
	else if (nb == count++)
		fct("%.20u", UINT_MAX);
	else if (nb == count++)
		fct("%.20u", UINT_MAX + 1);
	else if (nb == count++)
		fct("%.0x", 0);
	else if (nb == count++)
		fct("%.1x", 0);
	else if (nb == count++)
		fct("%.2x", 0);
	else if (nb == count++)
		fct("%.0x", 5);
	else if (nb == count++)
		fct("%.1x", 5);
	else if (nb == count++)
		fct("%.2x", 5);
	else if (nb == count++)
		fct("%.0x", 42);
	else if (nb == count++)
		fct("%.1x", 42);
	else if (nb == count++)
		fct("%.2x", 42);
	else if (nb == count++)
		fct("%.3x", 42);
	else if (nb == count++)
		fct("%.10x", 42);
	else if (nb == count++)
		fct("%.6x", 100);
	else if (nb == count++)
		fct("%.0x", -1);
	else if (nb == count++)
		fct("%.1x", -1);
	else if (nb == count++)
		fct("%.2x", -1);
	else if (nb == count++)
		fct("%.3x", -1);
	else if (nb == count++)
		fct("%.0x", -42);
	else if (nb == count++)
		fct("%.1x", -42);
	else if (nb == count++)
		fct("%.3x", -42);
	else if (nb == count++)
		fct("%.4x", -42);
	else if (nb == count++)
		fct("%.20x", UINT_MAX);
	else if (nb == count++)
		fct("%.20x", UINT_MAX + 1);
	else if (nb == count++)
		fct("%.0X", 0);
	else if (nb == count++)
		fct("%.1X", 0);
	else if (nb == count++)
		fct("%.2X", 0);
	else if (nb == count++)
		fct("%.0X", 5);
	else if (nb == count++)
		fct("%.1X", 5);
	else if (nb == count++)
		fct("%.2X", 5);
	else if (nb == count++)
		fct("%.0X", 42);
	else if (nb == count++)
		fct("%.1X", 42);
	else if (nb == count++)
		fct("%.2X", 42);
	else if (nb == count++)
		fct("%.3X", 42);
	else if (nb == count++)
		fct("%.10X", 42);
	else if (nb == count++)
		fct("%.6X", 100);
	else if (nb == count++)
		fct("%.0X", -1);
	else if (nb == count++)
		fct("%.1X", -1);
	else if (nb == count++)
		fct("%.2X", -1);
	else if (nb == count++)
		fct("%.3X", -1);
	else if (nb == count++)
		fct("%.0X", -42);
	else if (nb == count++)
		fct("%.1X", -42);
	else if (nb == count++)
		fct("%.3X", -42);
	else if (nb == count++)
		fct("%.4X", -42);
	else if (nb == count++)
		fct("%.20X", UINT_MAX);
	else if (nb == count++)
		fct("%.20X", UINT_MAX + 1);
	else if (nb == count++)
		fct("%.0p", NULL);
	else if (nb == count++)
		fct("%.1p", NULL);
	else if (nb == count++)
		fct("%.6p", NULL);
	else if (nb == count++)
		fct("%.7p", NULL);
	else if (nb == count++)
		fct("%.0p", (void*)42);
	else if (nb == count++)
		fct("%.2p", (void*)42);
	else if (nb == count++)
		fct("%.5p", (void*)42);
	else if (nb == count++)
		fct("%.0p", (void*)ULONG_MAX);
	else if (nb == count++)
		fct("%.1p", (void*)ULONG_MAX);
	else if (nb == count++)
		fct("%.40p", (void*)ULONG_MAX);

	// [Tests with .-]
	else if (nb == count++)
		fct("%.-0%");
	else if (nb == count++)
		fct("%.-1%");
	else if (nb == count++)
		fct("%.-2%");
	else if (nb == count++)
		fct("%.-10%");
	else if (nb == count++)
		fct("%.-0c", '1');
	else if (nb == count++)
		fct("%.-1c", '1');
	else if (nb == count++)
		fct("%.-2c", '1');
	else if (nb == count++)
		fct("%.-10c", '1');
	else if (nb == count++)
		fct("%.-0s", NULL);
	else if (nb == count++)
		fct("%.-1s", NULL);
	else if (nb == count++)
		fct("%.-6s", NULL);
	else if (nb == count++)
		fct("%.-10s", NULL);
	else if (nb == count++)
		fct("%.-0s", "");
	else if (nb == count++)
		fct("%.-1s", "");
	else if (nb == count++)
		fct("%.-3s", "");
	else if (nb == count++)
		fct("%.-0s", "Hello");
	else if (nb == count++)
		fct("%.-1s", "Hello");
	else if (nb == count++)
		fct("%.-2s", "Hello");
	else if (nb == count++)
		fct("%.-5s", "Hello");
	else if (nb == count++)
		fct("%.-6s", "Hello");
	else if (nb == count++)
		fct("%.-7s", "Hello");
	else if (nb == count++)
		fct("%.-0d", 0);
	else if (nb == count++)
		fct("%.-1d", 0);
	else if (nb == count++)
		fct("%.-2d", 0);
	else if (nb == count++)
		fct("%.-0d", 5);
	else if (nb == count++)
		fct("%.-1d", 5);
	else if (nb == count++)
		fct("%.-2d", 5);
	else if (nb == count++)
		fct("%.-0d", 42);
	else if (nb == count++)
		fct("%.-1d", 42);
	else if (nb == count++)
		fct("%.-2d", 42);
	else if (nb == count++)
		fct("%.-3d", 42);
	else if (nb == count++)
		fct("%.-10d", 42);
	else if (nb == count++)
		fct("%.-6d", 100);
	else if (nb == count++)
		fct("%.-0d", -1);
	else if (nb == count++)
		fct("%.-1d", -1);
	else if (nb == count++)
		fct("%.-2d", -1);
	else if (nb == count++)
		fct("%.-3d", -1);
	else if (nb == count++)
		fct("%.-0d", -42);
	else if (nb == count++)
		fct("%.-1d", -42);
	else if (nb == count++)
		fct("%.-3d", -42);
	else if (nb == count++)
		fct("%.-4d", -42);
	else if (nb == count++)
		fct("%.-20d", INT_MAX);
	else if (nb == count++)
		fct("%.-20d", INT_MAX + 1);
	else if (nb == count++)
		fct("%.-20d", INT_MIN);
	else if (nb == count++)
		fct("%.-20d", INT_MIN - 1);
	else if (nb == count++)
		fct("%.-0i", 0);
	else if (nb == count++)
		fct("%.-1i", 0);
	else if (nb == count++)
		fct("%.-2i", 0);
	else if (nb == count++)
		fct("%.-0i", 5);
	else if (nb == count++)
		fct("%.-1i", 5);
	else if (nb == count++)
		fct("%.-2i", 5);
	else if (nb == count++)
		fct("%.-0i", 42);
	else if (nb == count++)
		fct("%.-1i", 42);
	else if (nb == count++)
		fct("%.-2i", 42);
	else if (nb == count++)
		fct("%.-3i", 42);
	else if (nb == count++)
		fct("%.-10i", 42);
	else if (nb == count++)
		fct("%.-6i", 100);
	else if (nb == count++)
		fct("%.-0i", -1);
	else if (nb == count++)
		fct("%.-1i", -1);
	else if (nb == count++)
		fct("%.-2i", -1);
	else if (nb == count++)
		fct("%.-3i", -1);
	else if (nb == count++)
		fct("%.-0i", -42);
	else if (nb == count++)
		fct("%.-1i", -42);
	else if (nb == count++)
		fct("%.-3i", -42);
	else if (nb == count++)
		fct("%.-4i", -42);
	else if (nb == count++)
		fct("%.-20i", INT_MAX);
	else if (nb == count++)
		fct("%.-20i", INT_MAX + 1);
	else if (nb == count++)
		fct("%.-20i", INT_MIN);
	else if (nb == count++)
		fct("%.-20i", INT_MIN - 1);
	else if (nb == count++)
		fct("%.-0u", 0);
	else if (nb == count++)
		fct("%.-1u", 0);
	else if (nb == count++)
		fct("%.-2u", 0);
	else if (nb == count++)
		fct("%.-0u", 5);
	else if (nb == count++)
		fct("%.-1u", 5);
	else if (nb == count++)
		fct("%.-2u", 5);
	else if (nb == count++)
		fct("%.-0u", 42);
	else if (nb == count++)
		fct("%.-1u", 42);
	else if (nb == count++)
		fct("%.-2u", 42);
	else if (nb == count++)
		fct("%.-3u", 42);
	else if (nb == count++)
		fct("%.-10u", 42);
	else if (nb == count++)
		fct("%.-6u", 100);
	else if (nb == count++)
		fct("%.-0u", -1);
	else if (nb == count++)
		fct("%.-1u", -1);
	else if (nb == count++)
		fct("%.-2u", -1);
	else if (nb == count++)
		fct("%.-3u", -1);
	else if (nb == count++)
		fct("%.-0u", -42);
	else if (nb == count++)
		fct("%.-1u", -42);
	else if (nb == count++)
		fct("%.-3u", -42);
	else if (nb == count++)
		fct("%.-4u", -42);
	else if (nb == count++)
		fct("%.-20u", UINT_MAX);
	else if (nb == count++)
		fct("%.-20u", UINT_MAX + 1);
	else if (nb == count++)
		fct("%.-0x", 0);
	else if (nb == count++)
		fct("%.-1x", 0);
	else if (nb == count++)
		fct("%.-2x", 0);
	else if (nb == count++)
		fct("%.-0x", 5);
	else if (nb == count++)
		fct("%.-1x", 5);
	else if (nb == count++)
		fct("%.-2x", 5);
	else if (nb == count++)
		fct("%.-0x", 42);
	else if (nb == count++)
		fct("%.-1x", 42);
	else if (nb == count++)
		fct("%.-2x", 42);
	else if (nb == count++)
		fct("%.-3x", 42);
	else if (nb == count++)
		fct("%.-10x", 42);
	else if (nb == count++)
		fct("%.-6x", 100);
	else if (nb == count++)
		fct("%.-0x", -1);
	else if (nb == count++)
		fct("%.-1x", -1);
	else if (nb == count++)
		fct("%.-2x", -1);
	else if (nb == count++)
		fct("%.-3x", -1);
	else if (nb == count++)
		fct("%.-0x", -42);
	else if (nb == count++)
		fct("%.-1x", -42);
	else if (nb == count++)
		fct("%.-3x", -42);
	else if (nb == count++)
		fct("%.-4x", -42);
	else if (nb == count++)
		fct("%.-20x", UINT_MAX);
	else if (nb == count++)
		fct("%.-20x", UINT_MAX + 1);
	else if (nb == count++)
		fct("%.-0X", 0);
	else if (nb == count++)
		fct("%.-1X", 0);
	else if (nb == count++)
		fct("%.-2X", 0);
	else if (nb == count++)
		fct("%.-0X", 5);
	else if (nb == count++)
		fct("%.-1X", 5);
	else if (nb == count++)
		fct("%.-2X", 5);
	else if (nb == count++)
		fct("%.-0X", 42);
	else if (nb == count++)
		fct("%.-1X", 42);
	else if (nb == count++)
		fct("%.-2X", 42);
	else if (nb == count++)
		fct("%.-3X", 42);
	else if (nb == count++)
		fct("%.-10X", 42);
	else if (nb == count++)
		fct("%.-6X", 100);
	else if (nb == count++)
		fct("%.-0X", -1);
	else if (nb == count++)
		fct("%.-1X", -1);
	else if (nb == count++)
		fct("%.-2X", -1);
	else if (nb == count++)
		fct("%.-3X", -1);
	else if (nb == count++)
		fct("%.-0X", -42);
	else if (nb == count++)
		fct("%.-1X", -42);
	else if (nb == count++)
		fct("%.-3X", -42);
	else if (nb == count++)
		fct("%.-4X", -42);
	else if (nb == count++)
		fct("%.-20X", UINT_MAX);
	else if (nb == count++)
		fct("%.-20X", UINT_MAX + 1);
	else if (nb == count++)
		fct("%.-0p", NULL);
	else if (nb == count++)
		fct("%.-1p", NULL);
	else if (nb == count++)
		fct("%.-6p", NULL);
	else if (nb == count++)
		fct("%.-7p", NULL);
	else if (nb == count++)
		fct("%.-0p", (void*)42);
	else if (nb == count++)
		fct("%.-2p", (void*)42);
	else if (nb == count++)
		fct("%.-5p", (void*)42);
	else if (nb == count++)
		fct("%.-0p", (void*)ULONG_MAX);
	else if (nb == count++)
		fct("%.-1p", (void*)ULONG_MAX);
	else if (nb == count++)
		fct("%.-40p", (void*)ULONG_MAX);
	
	return (0);
}
