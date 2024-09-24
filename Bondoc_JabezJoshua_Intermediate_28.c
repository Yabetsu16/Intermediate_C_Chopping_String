#include <stdio.h>
#include <stdlib.h>

char *left(char *s,int len)
{
	char *buf;
	int x;

	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
		exit(1);

	for(x=0;x<len;x++)
		*(buf+x) = *(s+x);
	*(buf+x) = '\0';

	return(buf);
}

char *right(char *s,int len)
{
	char *buf;
	char *start;
	int x;

	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
		exit(1);

	start = s;
	while(*start!='\0')
	   start++;
	/* backup */
	for(x=0;x<len;x++)
		start--;

	for(x=0;x<len;x++)
		*(buf+x) = *(start+x);
	*(buf+x) = '\0';

	return(buf);
}

char *mid(char *s,int offset, int len)
{
	char *buf;
	int x;

	buf = (char *)malloc(sizeof(char)*len+1);
	if( buf==NULL )
		exit(1);

	for(x=0;x<len;x++)
	{
		*(buf+x) = *(s+offset+x);
		if( *(buf+x)=='\0')
			break;
	}
	*(buf+x) = '\0';

	return(buf);
}

int main()
{
	char string[] = "Once upon a time, there was a string";

	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16,left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,12,11));

	return(0);
}
