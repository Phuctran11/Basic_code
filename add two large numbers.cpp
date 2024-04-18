#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char num1[50], num2[50], sum[50];
	int k,i,s,d1,d2;
	scanf("%s %s ", &num1, &num2);
	int l1=strlen(num1);
	int l2=strlen(num2);
	while (l1<l2){
		num1='0' + num1;
	}
	while (l1>l2){
		num2='0' + num2;
	}
    k =l1 > l2 ? l1:l2;
    for (i=k-1; i>=0; i--){
    	s=(num1[i]-'0')+(num2[i]-'0');
    	if(s>=10){
		d1=s%10;
    	d2=s-10*d1;
    	sum[i]=d2+'0';
    	s=(num1[i-1]-'0')+(num2[i-1]-'0')+d1;
        }
        else{sum[i]=s+'0';
		}
    	
	}
	printf("%s", sum);
	return 0;
	
}
