/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:45:37 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/18 16:22:00 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_last_read_line(char last[BUFFER_SIZE], char **line)
{
	size_t	rs;
	int		fllen;

	rs = sch(last, '\n', 0);
	fllen = 0;
	if (rs + 1 < BUFFER_SIZE)
		fllen = sch(last, '\n', rs + 1) - rs;
	if (fllen > 0)
		*line = strcat_m(*line, last + rs + 1, fllen);
	if (last[rs] == '\n')
		last[rs] = '?';
	return (sch(last, '\n', 0) == BUFFER_SIZE);
}

char	*check_line(char *line, int reads)
{
	if (line && reads == 0)
		free(line);
	if (reads == 0)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	last[4096][BUFFER_SIZE];
	char		buffer[BUFFER_SIZE];
	char		*line;
	int			rs;
	int			reads;

	reads = 0;
	line = NULL;
	if (fd <= 0 || fd >= 4096)
		return (NULL);
	ft_memcpy(buffer, NULL, BUFFER_SIZE, 0);
	rs = get_last_read_line(last[fd], &line);
	if (rs)
		ft_memcpy(last[fd], NULL, BUFFER_SIZE, 0);
	reads += (int)(line != NULL);
	while (sch(buffer, '\n', 0) == BUFFER_SIZE && rs > 0)
	{
		ft_memcpy(buffer, NULL, BUFFER_SIZE, 0);
		rs = read(fd, buffer, BUFFER_SIZE);
		reads += rs;
		if (rs > 0)
			line = strcat_m(line, buffer, sch(buffer, '\n', 0) + 1);
		ft_memcpy(last[fd], buffer, BUFFER_SIZE, -1);
	}
	return (check_line(line, reads));
}
