#include "get_next_line.h"

void	*ft_memcpy(void *to, const void *from, size_t nbytes)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*f;

	i = 0;
	t = (unsigned char *)to;
	f = (unsigned char *)from;
	if (!to && !from)
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
	while(buffer[i] && buffer[i] != '\n')
	{
		i ++;
	}
	if (buffer[i] == '\n')
	{
		str = (char *)malloc(sizeof(char) * (i + 2));
		if (!str)
			return (NULL);
		ft_memcpy(str,buffer,i);
		str[i] = '\n';
		str[i + 1] = '\0';
		return (str);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		ft_memcpy(str,buffer,i);
		str[i] = '\0';
		return (str);
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		nbytes;
	char		read_buffer[BUFFER_SIZE + 1];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while(!has_newline(buffer))
	{
		nbytes = read(fd,read_buffer,BUFFER_SIZE);
		if (nbytes <= 0)
		{
			if (buffer && buffer[0] != '\0')
			{
				str = get_line(buffer);
				free(buffer);
				buffer = NULL;
				return (str);
			}
			return (NULL);
		}
		read_buffer[nbytes] = '\0';
		buffer = join_buffers(buffer,read_buffer);
	}

	str = get_line(buffer);
	buffer = buffer_resize(buffer,str);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		buffer = NULL;
	}
	return (str);
}

// int main()
// {
// 	int	fd;

// 	fd = open("gnlrd.txt",O_RDONLY);
// 	for (size_t i = 0; i < 10; i ++)
// 	{
// 		printf("ln %s\n",get_next_line(fd));
// 	}
// 	close(fd);
// }
