#include <stdio.h>
#include <ctype.h>

enum{SUCCESS, FAIL};


void change_upper(FILE *file)
{
	int c;
	while ( (c = fgetc(file)) != EOF)
	{
		if (isalpha(c))
		{
			c=toupper(c); /*neu c la chu cai thi chuyen thanh chu in hoa */
			fseek(file, -1, SEEK_CUR); /* quay lai va ghi de du lieu */
			fputc(c, file);
			putchar(c); /*hien thi ki tu c tren man hinh */
		}
	}
}

int main(int argc, char* argv[])
{
	FILE *fptr;
	int reval=SUCCESS;
	// kiem tra so doi so va huong dan cu phap dung
	if(argc != 2)
	{
		printf ("Wrong number of arguments!\n");
		printf ("CORRECT SYNTAX: %s <file>\n", argv[0]);
		reval = FAIL;
	}
	//kiem tra file co mo duoc khong
	else if ( (fptr = fopen(argv[1], "r+")) == NULL)
	{
		printf ("Cannot open %s.\n", argv[1]);
		reval = FAIL;
	}
	//thuc hien chuyen thanh chu in hoa
	else{
		change_upper(fptr);
		fclose(fptr);
	}
	return reval;
	
}
