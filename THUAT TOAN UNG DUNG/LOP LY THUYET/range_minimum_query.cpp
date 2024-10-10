#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int M[20][100000];; 
    for (int i = 0; i < n; i++) {
        cin >> M[0][i];
    }

    for (int i = 1; (1 << i) <= n; i++) { //(1<<j) = 2^j
        for (int j = 0; j + (1 << i) - 1 < n; j++) {
            if (M[i - 1][j] < M[i - 1][j + (1 << (i - 1))]) {
                M[i][j] = M[i - 1][j];
            } else {
                M[i][j] = M[i - 1][j + (1 << (i - 1))];
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
        if(M[log_len][i] < M[log_len][j - (1 << log_len) + 1]) {
            Q+=M[log_len][i];
        }
        else {
            Q+= M[log_len][j-(1<<log_len)+1];
        }
    }

    cout << Q << endl; 

    return 0;
}
