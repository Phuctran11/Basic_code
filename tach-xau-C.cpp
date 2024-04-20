#include <stdio.h>
#include <string.h>

char *subStr(char* s1, int offset , int number)
{
	int len=strlen(s1);
	if( number > (len - offset + 1) )
	{
		for (int i = offset; i<len; i++)
		{
			printf("%c", s1[i]);
		}
	}
	else{
		for(int i = offset; i< (offset + number); i++)
		{
			printf("%c", s1[i]);
		}
	}
}

int main()
{
	char str[1000];
	int offset, number;
	fgets(str, sizeof(str), stdin);
	scanf ("%d %d", &offset, &number);
 	subStr(str, offset, number);
	return 0;
}
