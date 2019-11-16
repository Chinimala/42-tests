/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/16 11:28:35 by aalleman    ###    #+. /#+    ###.fr     */
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

	// [End].
return (0);
}
