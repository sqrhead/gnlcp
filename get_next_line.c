#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif
#ifndef DEBUG 
# define DEBUG 0
#endif

typedef struct s_dynbuffer
{
	char 			*buffer;
	size_t			len;
	size_t			is_nl;
	struct s_dynbuffer	*next;

} t_dynbuffer;

t_dynbuffer	*dynbuff_getlst(const t_dynbuffer *head)
{
	t_dynbuffer	*tmp;

	if (!head)
		return (NULL);
	tmp = (t_dynbuffer *)head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	dynbuff_addback(t_dynbuffer *head,t_dynbuffer *new)
{
	t_dynbuffer	*lst;
	if (!new)
		return ;
	if (!head)
		head = new;
	lst = dynbuff_getlst(head);
	lst->next = new;
}


/*
 *	-- GET LINE UNTIL \n
 *	-- UP INDEX 
 *	-- CHECK EOF 
 *	-- FREE EVERYTHING USED
 *	-- 
 *
 * */
// free, malloc, read
// static char* to keep the state 
// static size_t as index for the next string to get
char	*get_next_line(int fd)
{
	static t_dynbuffer	*dynbuff;
	char			*tmpbuffer;
	char			*cpybuffer;
	size_t			rbytes;


	dynbuffer = (t_dynbuffer *)malloc(sizeof(t_dynbuffer *));
	if (!dynbuffer)
	{
		printf("BUFFER FAIL!\n");
		return (NULL);
	}
	tmpbuffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	// todo check
	rbytes = read(fd,tmpbuffer,BUFFER_SIZE);
	cpybuffer = strdup(tmpbuffer);
	dyn->buffer = cpybuffer;
			
	
	free(tmpbuffer);
}

int main()
{	

	size_t	fd;
	char	*ln;
	char	*ln2;
	size_t	i;
	size_t	iter;

	i = 0;
	iter = 11;
	fd = open("gnlrd.txt",O_RDONLY);
	while (i < iter)
	{
		ln = get_next_line(fd);
		if (ln == NULL)
		{
			printf("INFO : iter %li\n",i);
			printf("INFO : ln null\n");
		}
		else
		{
			printf("INFO : iter %li\n",i);
			printf("INFO : ln %s\n",ln);
		}
		i ++;
	}

	free(ln);
	close(fd);
}
