/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:45:18 by jde-meo           #+#    #+#             */
/*   Updated: 2023/10/18 16:16:53 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strcat_m(char *dest, char *src, int src_size)
{
	char	*str;
	size_t	len1;

	len1 = 0;
	if (dest)
		len1 = ft_strlen(dest);
	str = (char *)malloc((len1 + src_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	if (dest)
		ft_memcpy(str, dest, len1 + 1, -1);
	if (dest)
		free(dest);
	while (src_size-- > 0 && *src)
		str[len1++] = *src++;
	str[len1] = '\0';
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n, int value)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		if (value >= 0)
			d[i] = value;
		else
			d[i] = s[i];
		i++;
	}
	return (dest);
}

size_t	sch(char buffer[BUFFER_SIZE], char c, int start)
{
	int	i;

	i = start;
	while (i < BUFFER_SIZE && buffer[i] != c)
		i++;
	return (i);
}
