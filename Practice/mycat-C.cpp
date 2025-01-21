#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {SUCCESS, FAIL, MAX_LEN = 81, MAX_LINE = 25};

void read_full_file(FILE *file)
{
	char buff[MAX_LEN];
	while (fgets(buff, MAX_LEN, file) != NULL)
	{
		printf("%s", buff);
	}
}

void read_divide_file(FILE *file)
{
	char buff[MAX_LEN];
	int count = 0;
	while (fgets(buff, MAX_LEN, file) != NULL)
	{
		printf ("%s", buff);
		count ++;
		if( (count % MAX_LINE) == 0) //chuyen trang khi so dong la boi cua MAX_LINE
		{
			printf ("Please enter the 'Space' button to go the next page!\n");
			getchar(); //nhan 
		}
	}
}


int main (int argc, char *argv[])
{
	FILE *fptr;
	int reval =  SUCCESS;
	if( argc < 2)
	{
		printf ("Wrong number of arguments!\n");
		printf ("CORRECT SYNTAX: cat <filename> -p\n");
		reval = FAIL;
	}
	else if ( (fptr = fopen(argv[1], "r")) == NULL)
	{
		printf ("Cannot open %s\n", argv[1]);
		reval = FAIL;
	}
	else{
		if (argc == 2)
		{
			read_full_file(fptr);
			fclose(fptr);
			printf ("The mission completed!\n");
			
		}
		else if (argc == 3 && strcmp(argv[2], "-p") == 0)
		{
			read_divide_file(fptr);
			fclose(fptr);
			printf ("The mission completed!\n");
		}
	}
	return reval;
}
