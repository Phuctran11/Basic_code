#include <stdio.h>
#include <stdlib.h>

enum {SUCCESS, FAIL, MAX_LEN = 81, MAX_LINE = 80};

void resolve(FILE *file)
{
	char buff[MAX_LEN];
	char first_character[MAX_LINE];
	int count = 0;
	while ((fgets(buff, MAX_LEN, file)) != NULL)
	{
		first_character[count] = buff[0];
		count++;
	}
	fseek(file, 0, SEEK_END);
	int c;
	for (int i = 0; i < count ; i++)
	{
		c=first_character[i];
		fputc(c, file);
		putchar (c);
	}
}


int main(int argc, char *argv[])
{
	FILE *fptr;
	int reval = SUCCESS;
	if (argc != 1)
	{
		printf("Wrong number of arguments!\n");
		printf ("CORRECT SYNTAX: <duong dan file>\n");
		reval = FAIL;
	}
	else if ( (fptr = fopen(argv[1], "r+")) == NULL)
	{
		printf ("Cannot open %s\n", argv[0] );
		reval = FAIL;
	}
	else {
		resolve(fptr);
		fclose (fptr);
		printf ("The mission completed!\n");
		
	}
	return reval;
}
