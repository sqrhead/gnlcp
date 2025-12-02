#include "get_next_line.h"

char	*get_next_line(int fd)
{
}

int main()
{
	printf("GNL\n");
	char buffer[100] = "ornitorinco"; 
	printf("buffer : %s\n",buffer);
	size_t nbytes = read(1,buffer,12);
	printf("bytes : %lu\n",nbytes);
}
