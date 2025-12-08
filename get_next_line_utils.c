/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:40:29 by sqrhead           #+#    #+#             */
/*   Updated: 2025/12/08 22:31:08 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}

char	*join_buffers(char *buffer, char *read_buffer)
{
	char	*nbuffer;
	int		i;
	int		j;

	j = 0;
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	nbuffer = (char *)malloc(ft_strlen(buffer) + ft_strlen(read_buffer) + 1);
	if (!nbuffer)
		return (NULL);
	i = ft_strlen(buffer);
	ft_memcpy(nbuffer, buffer, i);
	while (read_buffer[j])
	{
		nbuffer[i + j] = read_buffer[j];
		j ++;
	}
	nbuffer[i + j] = '\0';
	free(buffer);
	return (nbuffer);
}

char	*buffer_resize(char *buffer, char *str)
{
	char	*nbuffer;
	size_t	s_len;
	size_t	buf_len;

	if (!buffer)
		return (NULL);
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	s_len = ft_strlen(str);
	buf_len = ft_strlen(buffer);
	nbuffer = (char *)malloc(buf_len - s_len + 1);
	if (!nbuffer)
		return (NULL);
	ft_memcpy(nbuffer, buffer + s_len, buf_len - s_len);
	nbuffer[buf_len - s_len] = '\0';
	free(buffer);
	return (nbuffer);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i ++;
	}
	return (i);
}
