#include <stdio.h>
#include <string.h>

int main()
{
    char tt[1000];
    fgets(tt, sizeof(tt), stdin);
    int l=strlen(tt);
     int space_count = 0;
    //Xoa dau cach o dau dong
    while (tt[0]==' '){
        for (int i=0; i<l; i++)
        {
            tt[i]=tt[i+1];
        }
    	l--;
    }
    //Xoa dau cach o cuoi dong
    while(tt[l-1]==' ')
    {
        tt[l-1]='\0';
        l--;
    }
    
    //Xoa dau cach o giua dong
    
    for (int i = 0; i < l; i++) {
        if (tt[i] == ' ' && tt[i + 1] == ' ') {
            for (int j = i; j < l; j++) {
                tt[j] = tt[j + 1];
            }
            l--;
            i--;
        }
    }

    printf ("%s", tt);
    return 0;
    
    
    
    
    
    
    
    
    
    
}
