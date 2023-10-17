/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:45:52 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/17 16:59:32 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*strcat_m(char *dest, char *src, int src_size);
void	*ft_memcpy(void *dest, const void *src, size_t n, int value);
size_t	search_char(char buffer[BUFFER_SIZE], char c, int start);
int		ft_strlen(const char *str);

#endif
