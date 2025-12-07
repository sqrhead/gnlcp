#include "get_next_line.h"

int	has_newline(char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	while(buffer[i])
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!buffer)
	{
		buffer = (char *)malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!read_buffer)
		return (NULL);
	nbuffer = (char *)malloc(strlen(buffer) + strlen(read_buffer) + 1);
	if (!nbuffer)
		return (NULL);
	while (buffer[i])
	{
		nbuffer[i] = buffer[i];
		i ++;
	}
	while(read_buffer[j])
	{
		nbuffer[i + j] = read_buffer[j];
		j ++;
	}
	free(buffer);
	nbuffer[i + j] = '\0';
	return (nbuffer);
}

char 	*buffer_resize(char *buffer, char *str)
{
	char	*nbuffer;
	size_t	s_len;
	size_t	j;
	size_t	i;

	j = 0;
	if (!buffer)
		return (NULL);
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	s_len = strlen(str);
	nbuffer = (char *)malloc(strlen(buffer) - s_len + 1);
	if(!nbuffer)
		return (NULL);
	i = s_len;
	while(buffer[i])
	{
		nbuffer[j] = buffer[i];
		i ++;
		j ++;
	}
	free(buffer);
	nbuffer[j] = '\0';
	//nbuffer = join_buffers(nbuffer,&buffer[i]);
	return (nbuffer);

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
		memcpy(str,buffer,i);
		str[i] = '\n';
		str[i + 1] = '\0';
		return (str);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (!str)
			return (NULL);
		memcpy(str,buffer,i);
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
 
int main()
{
	int	fd;

	fd = open("gnlrd.txt",O_RDONLY);
	for (size_t i = 0; i < 10; i ++)
	{
		printf("ln %s\n",get_next_line(fd));
	}
	close(fd);
}
