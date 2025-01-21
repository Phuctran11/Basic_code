// Given a sequence of distinct elements a1, a2, …, aN and a value b
// Count the number Q fo pairs (ai, aj) having ai+aj = b( i<j).

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int countpairs(int arr[], int n, int b)
{
    int count = 0;
    qsort(arr, n, sizeof(int), cmpfunc);
    
    int i = 0;
    int j = n - 1;
    while (i<j)
    {
        if ( arr[i] + arr[j] == b)
        {
            while( i<j && arr[i] == arr[i+1])
            {
                i++;
            }
            while ( i<j && arr[j] == arr[j-1])
            {
                j--;
            }

            count++;
            i++;
            j--;
        }
        else if( arr[i] + arr[j] < b)
        {
            i++;
        }
        else {
            j--;
        }
    }
    return count;
}

int main()
{
    int n, b;
    scanf("%d %d", &n, &b);
    int arr[n];
    for ( int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int N = sizeof(arr) / sizeof (arr[0]);
    printf("%d\n", countpairs(arr, N, b));
    return 0;
}
