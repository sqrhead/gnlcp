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
	size_t 	len;
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
	size_t		nbytes;
	static size_t	index;
	static char	*str;
	char		*line;

	nbytes = 0;
	index = 0;
	if (str == NULL )
		str = (char *)calloc(BUFFER_SIZE,sizeof(char));
	if (str[0] == '\0')
	{	
		printf("str empty \n");
		nbytes = read(fd,str,BUFFER_SIZE);
	}
	if (nbytes < 0)
		return (NULL);
	if (index < BUFFER_SIZE)
	{	
		line = str_inl(str,index);
		index ++;
		//free(str);
		return (line);
	}
	printf("FAIL_GET_NEXT_LINE\n");
	return (NULL);
}

int main()
{		
	// File Descript 	
	int 	fd;
	// Buffer for write mode
	/*
	char	*buffr;
	char	*buffx;
	char	*buffy;

	fd = open("gnlrd.txt",O_RDONLY);
	buffr = get_next_line(fd);
	printf("output  [ %s ]\n",buffr);
	buffx = get_next_line(fd);
	printf("outputx [ %s ]\n",buffx);
	buffy = get_next_line(fd);
	printf("outputy [ %s ]\n",buffy);

	free(buffr);	
	free(buffx);
	free(buffy);
	close(fd);
	*/

	if (DEBUG == 1)
	{
		printf("*********************************************\n");
		printf("- DEBUG_MODE\n");
		printf("*********************************************\n");
		static size_t	_internal_index = 0;
		static char	*_ibuffer; 
		size_t		_ibytes;
		size_t		_ifd;
		char		*str;

		_ibuffer = (char *)malloc(sizeof(char) * 1024); 
		str = NULL;
		if (!_ibuffer)
		{
			printf("FAILED_MALLOC\n");
			return (1);
		}
		_ifd = open("gnlrd.txt",O_RDONLY);
		_ibytes = read(_ifd,_ibuffer,40);
		printf("%s\n",_ibuffer);
		// count until new line
		size_t	len = 0;
		size_t	i = 0;
		while (_ibuffer[i])
		{	
			if (_ibuffer[i] == EOF)
			{
				printf("EOF REACHED\n");
				return (1);
			}
			if (_ibuffer[i] == '\n')
				break;
			len ++;
			i ++;	
		}
		// malloc and cpy
		str = (char *)malloc(sizeof(char) * (len + 1));
		memcpy(str,_ibuffer,len);
		printf("str : %s\n",str);
		_internal_index += len;
		
		
		free(_ibuffer);
		close(_ifd);
	}
	
}
