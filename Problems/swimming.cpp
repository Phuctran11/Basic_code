#include <iostream>

using namespace std;

int main(){
    int N,k;
    cin >> N >> k;
    int a = 0, n = 0;
    while ( N > 0)
    {
        N = N - k;
        a++ ;
        n = n + a;
    }
    cout << n;
    return 0;
    
}
    
