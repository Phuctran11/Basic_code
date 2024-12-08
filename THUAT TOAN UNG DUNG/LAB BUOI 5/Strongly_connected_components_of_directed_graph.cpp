#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

#define maxn 100005
using namespace std;

int n, m;
vector<int> A[maxn];
vector<int> A1[maxn]; // Residual graph
int f[maxn]; // Finish time
char color[maxn];
int t;
int icc[maxn]; // Index of connected component containing v
int ncc; // Number of connected components in the second DFS
int x[maxn]; // Sorted list (decreasing of finishing time) of nodes visited by DFS
int idx;

void buildResidualGraph() {
    for (int u = 1; u <= n; u++) {
        for (int j = 0; j < A[u].size(); j++) {
            int v = A[u][j];
            A1[v].push_back(u);
        }
    }
}

void init() {
    for (int v = 1; v <= n; v++) {
        color[v] = 'w';
    }
    t = 0;
}

// DFS for the original graph
void dfsA(int s) {
    t++;
    color[s] = 'g';
    for (int j = 0; j < A[s].size(); j++) {
        int v = A[s][j];
        if (color[v] == 'w') {
            dfsA(v);
        }
    }
    t++;
    f[s] = t;
    color[s] = 'b';
    idx++;
    x[idx] = s;
}

void dfsA() {
    init();
    idx = 0;
    for (int v = 1; v <= n; v++) {
        if (color[v] == 'w') {
            dfsA(v);
        }
    }
}

// DFS on the residual graph
void dfsA1(int s) {
    t++;
    color[s] = 'g';
    icc[s] = ncc;
    for (int j = 0; j < A1[s].size(); j++) {
        int v = A1[s][j];
        if (color[v] == 'w') {
            dfsA1(v);
        }
    }
    color[s] = 'b';
}

void dfsA1() {
    init();
    ncc = 0;
    for (int i = n; i >= 1; i--) {
        int v = x[i];
        if (color[v] == 'w') {
            ncc++;
            dfsA1(v);
        }
    }
}

void solve() {
    dfsA();
    buildResidualGraph();
    dfsA1();
    cout << ncc << endl;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        A[u].push_back(v);
    }
}

int main() {
    input();
    solve();
    return 0;
}