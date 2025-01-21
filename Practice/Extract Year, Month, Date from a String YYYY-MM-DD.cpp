#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
	
	char date[1000];
	scanf("%s", &date);
	int nam, thang, ngay;
	int length=strlen(date);
	int dem=0;
	for(int i=0; i<length; i++){
		if(date[i]=='-'){
		   dem++;	
		}
	}
	if(dem!=2 || length!=10){
		printf("INCORRECT");
	}
	else{
		nam=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
		thang=(date[5]-'0')*10+(date[6]-'0');
		ngay=(date[8]-'0')*10+(date[9]-'0');
	
		if(thang>12 || ngay>31){
			printf("INCORRECT");
		}
		else{
			printf("%d %d %d ", nam, thang, ngay);
		}
    }
    return 0;

}

