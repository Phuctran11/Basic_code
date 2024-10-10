#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int maxVal[4 * MAXN]; 
int a[MAXN];

void build(int id, int L, int R) {
    if (L == R) {
        maxVal[id] = a[L];
    } else {
        int m = (L + R) / 2;
        build(2 * id, L, m);
        build(2 * id + 1, m + 1, R);
        maxVal[id] = max(maxVal[2 * id], maxVal[2 * id + 1]);
    }
}

int getMaxFromNode(int id, int L, int R, int i, int j) {
    if (i > R || j < L) return -1; 
    if (i <= L && j >= R) return maxVal[id]; 
    int m = (L + R) / 2;
    return max(getMaxFromNode(2 * id, L, m, i, j),
               getMaxFromNode(2 * id + 1, m + 1, R, i, j));
}

void updateFromNode(int id, int L, int R, int index, int value) {
    if (L > R) return;
    if (index < L || index > R) return; 
    if (L == R) {
        maxVal[id] = value; 
        return;
    }
    int m = (L + R) / 2;
    updateFromNode(2 * id, L, m, index, value);
    updateFromNode(2 * id + 1, m + 1, R, index, value);
    maxVal[id] = max(maxVal[2 * id], maxVal[2 * id + 1]);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    build(1, 0, n - 1); 
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        string command;
        cin >> command;
        if (command == "get-max") {
            int x, y;
            cin >> x >> y;
            cout << getMaxFromNode(1, 0, n - 1, x - 1, y - 1) << endl; 
        } else if (command == "update") {
            int index, value;
            cin >> index >> value;
            updateFromNode(1, 0, n - 1, index - 1, value); 
        }
    }
}