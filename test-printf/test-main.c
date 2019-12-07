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
return (0);
}
