/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqrhead <sqrhead@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 13:40:26 by sqrhead           #+#    #+#             */
/*   Updated: 2025/12/08 23:15:38 by sqrhead          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *to, const void *from, size_t nbytes)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*f;

	i = 0;
	t = (unsigned char *)to;
	f = (unsigned char *)from;
	if (!to || !from)
		return (NULL);
	while (i < nbytes)
	{
		t[i] = f[i];
		i ++;
	}
	return (to);
}

char	*get_line(char *buffer)
{
	size_t	i;
	char	*str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i ++;
	}
	if (buffer[i] == '\n')
	{
		str = (char *)malloc(sizeof(char) * (i + 2));
		if (!str)
			return (NULL);
		ft_memcpy(str, buffer, i);
		str[i] = '\n';
		str[i + 1] = '\0';
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, buffer, i);
	str[i] = '\0';
	return (str);
}

char	*is_eof(char **buffer, char **read_buffer)
{
	char	*str;

	free(*read_buffer);
	*read_buffer = NULL;
	if (*buffer && (*buffer)[0] != '\0')
	{
		str = get_line(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (str);
	}
	return (NULL);
}

int	read_and_join(int fd, char **buffer, char *read_buffer)
{
	ssize_t	nbytes;

	while (!has_newline(*buffer))
	{
		nbytes = read(fd, read_buffer, BUFFER_SIZE);
		if (nbytes <= 0)
			return (0);
		read_buffer[nbytes] = '\0';
		*buffer = join_buffers(*buffer, read_buffer);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*read_buffer[MAX_FILE];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FILE)
		return (NULL);
	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	if (!read_and_join(fd, &buffer, read_buffer))
		return (is_eof(&buffer, &read_buffer));
	str = get_line(buffer);
	buffer = buffer_resize(buffer, str);
	free(read_buffer);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (str);
}

// int main()
// {
// 	int		fd;
// 	size_t	nlines = 10;
// 	fd = open("gnlrd.txt",O_RDONLY);
// 	for (size_t i = 0; i < nlines; i ++)
// 	{
// 		char *str = get_next_line(fd);
// 		printf("ln %s\n",str);
// 		free(str);
// 	}
// 	close(fd);
// }
