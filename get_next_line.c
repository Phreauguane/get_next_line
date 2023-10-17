/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:45:37 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/17 17:00:28 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_last_read_line(char	last[BUFFER_SIZE], char **line)
{
	size_t	rS;
	int		fllen;

	rS = search_char(last, '\n', 0);
	fllen = 0;
	if (rS + 1 < BUFFER_SIZE)
		fllen = search_char(last, '\n', rS + 1) - rS;
	*line = strcat_m(*line, last + rS + 1, fllen);
	if (rS < BUFFER_SIZE - 1)
		last[rS] = 'z';
	return (search_char(last, '\n', 0) == BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	last[1024][BUFFER_SIZE];
	char		buffer[BUFFER_SIZE];
	char		*line;
	size_t		endl;
	int			rS;

	line = NULL;
	if (fd <= 0)
		return (NULL);
	ft_memcpy(buffer, NULL, BUFFER_SIZE, 0);
	rS = get_last_read_line(last[fd], &line);
	while (search_char(buffer, '\n', 0) == BUFFER_SIZE && rS > 0)
	{
		rS = read(fd, buffer, BUFFER_SIZE);
		endl = search_char(buffer, '\n', 0);
		if (rS > 0)
			line = strcat_m(line, buffer, endl + 1);
		ft_memcpy(last[fd], buffer, BUFFER_SIZE, -1);
	}
	if (line && ft_strlen(line) == 0)
		return (NULL);
	return (line);
}
