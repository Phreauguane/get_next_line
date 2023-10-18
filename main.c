/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:04 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/18 15:42:36 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd1 = open("test.txt", O_RDONLY);
	int	fd2 = open("test2.txt", O_RDONLY);
	char	*str1, *str2;
	
	str1 = get_next_line(fd1);
	str2 = get_next_line(fd2);
	while (str1 || str2)
	{
		if (str1)
		{
			printf("%d : [%s]\n", fd1, str1);
			free(str1);
			str1 = get_next_line(fd1);
		}
		if (str2)
		{
			printf("%d : [%s]\n", fd2, str2);
			free(str2);
			str2 = get_next_line(fd2);
		}
	}
	close(fd1);	
	close(fd2);	
}