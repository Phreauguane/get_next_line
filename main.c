/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:04 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/19 15:54:07 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	//int	fd1 = open("lord_of_the_rings.txt", O_RDONLY);
	int	fd1 = open("test2.txt", O_RDONLY);
	char	*str1, *str2;
	int		calls = 0;

	while (1)
	{
		str1 = get_next_line(fd1);
		calls++;
		printf("[%s]", str1);
		free(str1);
		if (str1 == NULL)
			break;
	}
	printf("\n[%d]\n", calls);
	close(fd1);	
	//close(fd2);	
}