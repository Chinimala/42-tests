/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test-gnl.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aalleman <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/17 15:10:26 by aalleman     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 15:23:24 by aalleman    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(void)
{
	char	**line;

	get_next_line(-2, line);
	get_next_line(3, line);
	fd = open("filetestgnl", O_WRONLY | O_CREAT, 0777);
	close(fd);
	return (0);
}
