#include "get_next_line.h"

int	stop(char *buffer)
{
	size_t	i;

	i = 0;
	while(buffer[i])
	{
		if (buffer[i] == '\n')
		{
			return (1);
		}
		i ++;
	}
	return (0);
}

size_t	updt_index(char *buffer)
{	
	size_t	index;

	index = 0;
	while(buffer[index] && index < 1024)
	{
		index ++;
		if (index >= 1024)
		{
			index = 0;
			while (buffer[index])
			{
				buffer[index] = '\0';
				index ++;
			}
			return (0);
		}
	}
	return (index);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmpbuff[BUFFER_SIZE];
	size_t		nb;
	size_t		index;
	char		*str;
	char		*dup;
	size_t		len;

	if (!buffer)
	{
		buffer = (char *)calloc(1024,sizeof(char));
		if (!buffer)
		{
			return (NULL); // Fail
		}
	}
	index = 0;
	len = 0;
	index = updt_index(buffer);

	while (!stop(buffer) && index + BUFFER_SIZE < 1024)
	{
		nb = read(fd,&buffer[index],BUFFER_SIZE);
		if (nb == 0)
			return (NULL);
		index = updt_index(buffer);		
	}
	while(buffer[len] && buffer[len] != '\n')
	{
		len ++;
	}
	str = (char *)malloc(sizeof(char) * (len + 2));
	str[len] = '\n';
	str[len + 1] = '\0';
	memcpy(str,buffer,len);
	dup = strdup(buffer + len + 1);
	free(buffer);
	buffer = dup;
	return (str);
		
}

int main()
{	
	size_t	fd;

	fd = open("gnlrd.txt",O_RDONLY);
	for (size_t i = 0; i < 10; i ++)
	{
		printf("ln %s\n",get_next_line(fd));	
	}
	close(fd);
}


