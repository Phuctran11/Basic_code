
#include <stdio.h>
 enum {SUCCESS, FAIL};

int main(int argc, char* argv[])
{
	FILE *fptr1, *fptr2;
	int reval = SUCCESS;
	//check so doi so va huong dan
	if (argc != 3)
	{
		printf ("Wrong number of arguments!\n");
		printf ("CORRECT SYNTAX: mycp <tap_tin_1> <tap_tin_2>\n");
		reval = FAIL;
	}
	
	//Mo file nguon de doc

	else if ((fptr1 = fopen(argv[1], "r")) == NULL )
	{
		printf ("Cannot open the source file!\n");
		reval = FAIL;
	}
	
	//Mo file dich de ghi
	
	else if ((fptr2= fopen(argv[2], "w")) == NULL)
	{
		printf ("Cannot open the destiny file!\n");
		reval = FAIL;
	}
	
	
	//sao chep tung ki tu tu file nguon sang file dich
	else {
	char c;
	while ((c = fgetc(fptr1) != EOF))
	{
		fputc(c, fptr2);
		putchar(c);
	}
	//dong 2 file
	fclose(fptr1);
	fclose(fptr2);
	printf ("Copy successfully!");
	}
	return reval;
}
