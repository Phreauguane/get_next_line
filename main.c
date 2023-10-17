/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:33:04 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/17 17:00:09 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd = open("test.txt", O_RDONLY);
	char	*str;
	
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		printf("---\n");
		free(str);
		str = get_next_line(fd);
	}
	close(fd);	
}