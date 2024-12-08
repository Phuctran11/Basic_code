#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

const int N = 1e3 + 2;
int n, f[N][102], T, D, a[N], t[N], res;

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
}

void process() {
    memset(f, 0, sizeof(f));
    res = 0;

    // Initialize the first station
    for (int k = t[1]; k <= T; k++) {
        f[1][k] = a[1];
    }

    for (int i = 2; i <= n; i++) {
        for (int k = t[i]; k <= T; k++) {
            for (int j = max(1, i - D); j < i; j++) {
                if (k >= t[i]) {
                    f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
                }
            }
            res = max(res, f[i][k]);
        }
    }
    cout << res << endl;
}

int main() {
    input();
    process();
    return 0;
}