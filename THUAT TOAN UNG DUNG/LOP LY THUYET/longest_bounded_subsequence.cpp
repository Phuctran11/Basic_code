#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, Q;
    cin >> n >> Q;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int count = 0;
    int S = 0;
    int L = 0;
    for ( int R = 0; R<n; R++){
        S = S + a[R];
        while (S > Q){
            S = S - a[L];
            L++;
        }
        count  = max(count, R - L + 1);
    }
    cout << count << endl;
    return 0;
}