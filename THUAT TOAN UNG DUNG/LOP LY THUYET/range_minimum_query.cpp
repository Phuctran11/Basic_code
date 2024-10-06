#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n]; 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    int log_n = log2(n+1);
    int M[log_n][n]; 

    for (int i = 0; i < n; i++) {
        M[0][i] = i; 
    }

    for (int j = 1; (1 << j) <= n; j++) { //(1<<j) = 2^j
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            if (a[M[j - 1][i]] < a[M[j - 1][i + (1 << (j - 1))]]) {
                M[j][i] = M[j - 1][i];
            } else {
                M[j][i] = M[j - 1][i + (1 << (j - 1))];
            }
        }
    }

    int k;
    cin >> k; 
    int Q = 0; 

    for (int m = 0; m<k; m++) {
        int i, j;
        cin >> i >> j;
        int len = j - i + 1;
        int log_len = log2(len);
        int min_index = M[log_len][i];
        Q += a[min_index]; 
    }

    cout << Q << endl; 

    return 0;
}
