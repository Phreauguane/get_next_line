/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:08:33 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/22 21:17:09 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd[4096];
	int	fdsize = 0;

	if (ac == 1)
	{
		fd[0] = STDIN_FILENO;
		fdsize = 1;
	}
	else
	{
		fdsize = ac - 1;
		for (int i = 0; i < fdsize; i++)
		{
			if (av[i + 1][0] == '0' && av[i + 1][1] == '\0')
				fd[i] = STDIN_FILENO;
			else
				fd[i] = open(av[i + 1], O_RDONLY);
		}
	}
	for (int i = 0; i < fdsize; i++)
	{
		char	*line = "start";
		printf("--- %s ---\n", av[i + 1]);
		while (line != NULL)
		{
			line = get_next_line(fd[i]);
			printf(">%s", line);
			if (line != NULL)
				free(line);
		}
	}
}
