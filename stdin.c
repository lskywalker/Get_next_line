/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoopman <jkoopman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:29:36 by jkoopman       #+#    #+#                */
/*   Updated: 2020/01/09 13:36:52 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
/*
** Usage: ./a.out file1.txt
** This will EXACTLY copy the file to the terminal.
** Usefull to combine with a diff.
*/

int			main(void)
{
	int		fd;
	char	*line;
	int		res;

	fd = 0;
	res = 1;
	while (res > 0)
	{
		if (res > 0)
		{
			res = get_next_line(fd, &line);
			if (res == 0)
				printf("%s", line);
			else
				printf("%s\n", line);
			free(line);
		}
	}
	return (0);
}
