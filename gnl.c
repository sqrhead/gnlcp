#include "get_next_line.h"

int     stop(char *buffer)
{
        size_t  i;
	if (!buffer)
		return (0);
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

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len ++;
	return (len);
}
char	*buffer_join(char *buff, char *tmp)
{	
	char 	*joined;
	size_t	i;
	size_t	j;

	joined = NULL;
	i = 0;
	j = 0;

	if (!buff)
	{
		buff = (char *)malloc(sizeof(char));
		buff[0] = '\0';	
	}
	joined = (char *)malloc(ft_strlen(buff) + ft_strlen(tmp) + 1);
	if (!joined)
		return (NULL);
	while (buff[i])
	{
		joined[i] = buff[i];
		i ++;
	}
	while (tmp[j])
	{
		joined[i + j] = tmp[j];
		j ++;
	}
	joined[i + j] = '\0';
	free(buff);
	return (joined);
}

char	*fix_buffer(char *buffer)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i ++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)malloc(ft_strlen(buffer) - i);
	i ++;
	while (buffer[i])
	{
		tmp[j] = buffer[i];
		j ++;
		i ++;
	}
	tmp[j] = '\0';
	return (tmp);

}

char 	*get_line(const char *buffer)
{
	size_t	len;
	char	*str;

	len = 0;
	if (!buffer || buffer[0] == '\0')
		return (NULL);
	while(buffer[len] && buffer[len] != '\n')
		len ++;
	if (buffer[len] == '\n')
		len ++;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	memcpy(str,buffer,len);
	return (str);

}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		tmpbuff[BUFFER_SIZE + 1];
	char		*str;
	size_t		nb;
	
	// read 
	while (!stop(buffer))
	{
		nb = read(fd,tmpbuff,BUFFER_SIZE);
		if (nb == 0)
			return (NULL);
		tmpbuff[nb] = '\0';
		buffer = buffer_join(buffer,tmpbuff);
	}
	// check
	str = get_line(buffer);
	buffer = fix_buffer(buffer);
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


