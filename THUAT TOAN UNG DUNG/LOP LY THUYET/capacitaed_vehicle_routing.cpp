#include <bits/stdc++.h>
using namespace std;

int n, q, d[23][23], Cmin = 1e9, load = 0, f = 0, fbest = 1e9;
bool visited[23];

bool check(int i) {
    if (visited[i]) return false;
    if (i > n) {
        if (!visited[i - n]) return false;
    } else {
        if (load + 1 > q) return false;
    }
    return true;
}

void updateBest(int f, int lastD) {
    if (f + lastD < fbest) fbest = f + lastD;
}

void Try(int k, int curPos) {
    for (int i = 1; i <= 2 * n; i++) {
        if (check(i)) {
            if (i <= n) load++;
            else load--;

            f += d[curPos][i];
            visited[i] = true;

            if (k == 2 * n) {
                updateBest(f, d[i][0]);
            } else {
                if (f + Cmin * (2 * n + 1 - k) < fbest) {
                    Try(k + 1, i);
                }
            }

            if (i <= n) load--;
            else load++;

            visited[i] = false;
            f -= d[curPos][i];
        }
    }
}

int main() {
    memset(visited, false, sizeof(visited));
    cin >> n >> q;

    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> d[i][j];
            Cmin = min(d[i][j], Cmin);
        }
    }

    Try(1, 0);
    cout << fbest;
    return 0;
}
