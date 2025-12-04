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
	}
	return (index);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
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

	while (!stop(buffer))
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
	//buffer = buffer + len; 
	return (str);
		
}
int main()
{	
	size_t	fd;
	char	*str;

	fd = open("gnlrd.txt",O_RDONLY);
	for (size_t i = 0; i < 10; i ++)
	{
	
	}
	free(str);
	close(fd);
}
