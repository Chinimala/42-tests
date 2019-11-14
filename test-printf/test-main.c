/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 16:54:40 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 11:59:58 by jgambard    ###    #+. /#+    ###.fr     */
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
		return(ac == 2 ? printf("%g", 42.0) : ft_printf("%g", 42.0));
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

	// [A - Tests without options].
return (0);
}
