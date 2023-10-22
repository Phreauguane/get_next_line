/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 20:04:23 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/22 21:10:04 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_gnl
{
	char	buff[BUFFER_SIZE];
	int		read;
}	t_gnl;

char	*get_next_line(int fd);
char	*str_addc(char *str, char c);
char	*str_adds(char *str, char *s, size_t src_len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		stchr(char *s, char c);

#endif