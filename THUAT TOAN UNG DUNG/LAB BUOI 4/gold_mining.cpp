#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef pair<int, int> ii;
const int N = 1e6 + 2;
int n, l1, l2, a[N], f[N], res;
vector<ii> b;

void input() {
    cin >> n >> l1 >> l2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

priority_queue<ii> hd;

void process() {
    memset(f, 0, sizeof(f));
    res = 0;

    for (int i = 1; i <= n; i++) {
        if (i - l1 >= 0) hd.push(ii(f[i - l1], i - l1));
        while (!hd.empty()) {
            if (hd.top().second < i - l2) hd.pop();
            else break;
        }
        if (!hd.empty()) {
            f[i] = hd.top().first + a[i];
        } else {
            f[i] = a[i];
        }
        res = max(f[i], res);
    }
    cout << res << endl;
}

int main() {
    input();
    process();
    return 0;
}