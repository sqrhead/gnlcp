#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif
#ifndef DEBUG 
# define DEBUG 0
#endif
size_t	strlen_nl(char *str)
{
	size_t	len;
	size_t	index;

	index = 0;
	len = 0;
	while (str[len])
	{	
		if (str[len] == '\n')
		{
			return (len);
		}
		len ++;
	}
	return (len);
}
char *str_inl(const char *buff, const size_t index)
{
	size_t	len;
	size_t	i;
	size_t	counter;
	char	*str;

	if (!buff || index < 0)
		return (NULL);
	i = 0;
	counter = 0;
	while (buff[i] && counter < index)
	{
		i ++; 
		if (buff[i] == '\n')
			counter ++;
	}
	while (buff[i] && buff[i] != '\n')
	{
		len ++;
		i ++;
	}
	
	printf("_len %li\n",len);
	printf("_internal_index %li\n",i);
	str = (char *)malloc(sizeof(char) * len);
	memcpy(str,&buff[i-len],len);
	printf("_str %s\n",str);
	return (str);
		
}
// free, malloc, read
// static char* to keep the state 
// static size_t as index for the next string to get
char	*get_next_line(int fd)
{
		static size_t	internal_index = 0;
		static char		*buffer; 
		size_t			bytes;
		char			*str;
		size_t			len;
		size_t			i; 

		len = 0;
		i = 0;
		str = NULL;
		if (!buffer)
		{
			printf("calloc . . . \n");
			buffer = (char *)calloc(BUFFER_SIZE,sizeof(char));
			if (!buffer)
				return (NULL);
			printf("read . . .\n");
			bytes = read(fd,buffer,BUFFER_SIZE);
		}
		if (DEBUG == 1 && internal_index < 1)
		{
			printf("buffer : \n%s\n",buffer);
		}
		while (buffer[i + internal_index] && i + internal_index < BUFFER_SIZE)
		{	
			if (buffer[i + internal_index] == EOF)
			{
				printf("EOF REACHED\n");
				return (NULL);
			}
			if (buffer[i + internal_index] == '\n' || !buffer[i + internal_index])
				break;
			len ++;
			i ++;	
		}
		// malloc and cpy
		str = (char *)malloc(sizeof(char) * (len + 1));
		memcpy(str,buffer+internal_index,len);
		str[len] = '\0';
		internal_index += len + 1;
		printf("INFO : inter index %li\n",internal_index);
		return (str);
		
}

int main()
{	

	size_t	fd;
	char	*ln;
	char	*ln2;
	size_t	i;
	size_t	iter;

	i = 0;
	iter = 10;
	fd = open("gnlrd.txt",O_RDONLY);
	while (i < iter)
	{
		ln = get_next_line(fd);
		printf("ln %s\n",ln);
		i ++;
	}

	free(ln);
	close(fd);
}
