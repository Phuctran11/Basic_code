#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

enum{SUCCESS, FAIL, MAX_LEN=80, MAX_LENGTH=86};

void copy_block_optional_size(FILE *fin, FILE *fout)
{
	int num;
	char buff[MAX_LEN];
	while (!feof(fin))
	{
		num=fread(buff, sizeof(char), MAX_LEN, fin);
		buff[num*sizeof(char)]='\0';
		printf ("%s", buff);
		fwrite(buff, sizeof(char), num, fout);
		
	}
}

void copy_character(FILE *fin, FILE *fout)
{
	int c;
	while ( (c = fgetc(fin)) != EOF)
	{
		fputc(c, fout);
		putchar(c);
	}
}


void copy_line(FILE *fin, FILE *fout)
{
	char buff[MAX_LENGTH];
	while ( (fgets(buff, MAX_LENGTH, fin)) != NULL)
	{
		fputs(buff, fout);
		printf("%s", buff);
		
	}
}


int main(int argc, char *argv[])
{
	FILE *fptr1, *fptr2;
	int reval = SUCCESS;
	int n;
	printf ("Please choose one of three fuctions:\n");
	printf ("Copy by character --> Enter '1'\n");
	printf ("Copy by line --> Enter '2'\n");
	printf ("Copy by block optional size --> Enter '3'\n");
	printf ("Quit--> Enter '4'\n");
	scanf ("%d", &n);
	if (argc != 2)
	{
		printf ("Wrong number of arguments!\n");
		printf ("CORRECT SYNTAX: <file1> <file2>\n");
		reval = FAIL;
		
	}
	else if ( (fptr1 = fopen(argv[0], "r")) == NULL)
	{
		printf ("Cannot open the fin!\n");
		reval = FAIL;
	}
	else if ( ( fptr2 = fopen (argv[1], "w")) == NULL)
	{
		printf ("Cannot open the fout!\n");
		reval = FAIL;
	}
	else {
		switch (n)
		{
			case 1:
				clock_t start1, end1;
				double time_used1;
				start1 = clock();
				copy_character(fptr1, fptr2);
				end1 = clock();
				time_used1 = ((double) (end1 - start1)) / CLOCKS_PER_SEC * 1000;
    			printf("Time used: %.2lf milliseconds\n", time_used1);
				fclose (fptr1);
				fclose (fptr2);
				break;
			
			case 2:
				clock_t start2, end2;
				double time_used2;
				start2 = clock();
				copy_line(fptr1, fptr2);
				end2 = clock();
				time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC * 1000;
    			printf("Time used: %.2lf milliseconds\n", time_used2);
				fclose (fptr1);
				fclose (fptr2);
				break;
				
			case 3:
				clock_t start3, end3;
				double time_used3;
				start3 = clock();
				copy_block_optional_size(fptr1, fptr2);
				end3 = clock();
				time_used3 = ((double) (end3 - start3)) / CLOCKS_PER_SEC * 1000;
    			printf("Time used: %.2lf milliseconds\n", time_used3);
				fclose (fptr1);
				fclose (fptr2);
				break;
			
			default:
				fclose (fptr1);
				fclose (fptr2);
				
		}
	}
	return reval;

}
