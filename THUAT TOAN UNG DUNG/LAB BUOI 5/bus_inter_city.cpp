#include <bits/stdc++.h>
#define N 5001
#define INF 1e9
using namespace std;

int w[N][N];
int n,m;
int C[N], D[N];
int d[N];
bool f[N];
vector<int> A[N];

void BFS(int i){
    queue<int> Q;
    for (int j = 1; j<=n; j++) d[j] = -1;
    d[i] = 0; 
    Q.push(i);
    while (!Q.empty()){
        int v = Q.front(); 
        Q.pop();
        w[i][v] = C[i];
        for (int j = 0; j< A[v].size(); j++){
            int u = A[v][j];
            if(d[u] >= 0){
                continue;
            }
            d[u] = d[v] + 1;
            if(d[u] <= D[i]){
                Q.push(u);
            }
        }
    }
}

void buildGraph(){
    for (int i = 1; i<=n; i++){
        for (int j = 1; j<= n; j++){
            w[i][j] = INF;
        }
    }
    for (int i = 1; i<=n; i++){
        BFS(i);
    }
}

void dijkstra(int s, int t){
    for (int v = 1; v<=n; v++){
        d[v] = w[s][v];
        f[v] = false;
    }
    d[s] = 0;
    f[s] = true;
    for (int i = 1; i<=n; i++){
        int u = -1;
        int minD = INF;
        for (int v = 1; v<=n; v++){
            if(!f[v]){
                if(d[v] < minD){
                    u = v;
                    minD = d[v];
                }
            }
        }
        f[u] = true;
        if( u == t) break;
        for (int v = 1; v <= n; v++){
            if(!f[v]){
                if(d[v] > d[u] + w[u][v]){
                    d[v] = d[u] + w[u][v];
                }
            }
        }
    }
    cout << d[t] << endl;
}

void input(){
    cin >> n >> m;
    for (int i = 1; i<= n; i++){
        cin >> C[i] >> D[i];
    }
    for (int i = 1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }
}
void solve(){
    buildGraph();
    dijkstra(1, n);
}

int main(){
    input();
    solve();
    return 0;
}