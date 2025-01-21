#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum {SUCCESS, FAIL};

char Caesar(char ch, int offset)
{
	
	if (offset >= 0){
		if( ch >= 'A' && ch <= 'Z')
		{
			ch = ((ch - 'A' + offset) % 26) + 'A';
			
		}
		else if ( ch >= 'a' && ch <= 'z')
		{
			ch = ((ch - 'a' + offset) % 26) + 'a';
		}
	}
	else {
		if ( ch >= 'A' && ch <= 'Z')
		{
			int delta = abs((ch - 'A' + offset) % 26);
			ch = 'Z' - (delta - (ch - 'A') + 1);
		}
		else if ( ch >= 'a' && ch <= 'z')
		{
			int delta = abs((ch - 'a' + offset) % 26);
			ch = 'z' - (delta - (ch - 'z') + 1);
		}
	}
	return ch;
}


int main(int argc, char* argv[])
{
	FILE *fptr1, *fptr2;
	int reval = SUCCESS;
	if (argc != 3)
	{
		printf ("Wrong number of arguments!\n");
		printf ("CORRECT SYNTAX: <%s> <%s> <%s>\n", argv[0], argv[1], argv[2]);
		reval = FAIL;
	}
	else if ( (fptr1 = fopen (argv[0], "r")) == NULL)
	{
		printf ("Cannot open %s.\n", argv[0]);
		reval = FAIL;
	}
	else if ( (fptr2 = fopen (argv[2], "w")) == NULL)
	{
		printf ("Cannot open %s.\n", argv[2]);
		reval = FAIL;
	}
	else {
		int offset = atoi(argv[1]);
		int c;
		while ( (c = fgetc(fptr1)) != EOF){
			c = Caesar(c, offset);
			fputc(c, fptr2);
			putchar(c);
		}
		fclose (fptr1);
		fclose (fptr2);
		printf ("The Caesar proccess completed!\n");
	}
	return reval;
	
}

