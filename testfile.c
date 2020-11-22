/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   testfile.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoopman <jkoopman@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 13:44:55 by jkoopman       #+#    #+#                */
/*   Updated: 2019/12/04 14:03:09 by lsmit         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int			main(int argc, char *argv[])
{
	char	*line;
	int		fds[argc][3];
	int		cnt = 0;
	int		run = 1;
	if (argc == 1)
		return (0);
	for (int i = 0; i < argc; i++)
	{
		fds[i][0] = 1;
		fds[i][1] = 1;
		fds[i][2] = open(argv[i + 1], O_RDONLY);
	}
	printf("NUMBER OF FILES: %d\n", argc - 1);
	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
	printf("==========================================\n");
	while (run)
	{
		for (int file = 0; file < argc - 1; file++)
		{
			if (fds[file][1] >= 0)
			{
				fds[file][1] = get_next_line(fds[file][2], &line);
				if (fds[file][1] >= 0)
					free(line);
				printf("FILE: %s, LINE %d, OUT %d |%s|\n", argv[file + 1], fds[file][0]++, fds[file][1], line);
				cnt = 0;
				if (fds[file][1] == 0)
					fds[file][1] = -1;
			}
			else
				cnt++;
			if (cnt >= argc)
				run = 0;
		}
	}
	printf("==========================================\n");
	return (0);
}
