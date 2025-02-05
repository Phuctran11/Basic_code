/*Description
Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
Input
•Line 1: two positive integers N and M (1 <= N <= 10
4
, 1 <= M <= 10
6
)
•Line 2: contains 2 positive integers s and t
•Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of i
th
 arc
Output
  Write the value of the max-flow found
Example
Input
7 12
6 7
1 7 7
2 3 6
2 5 6
3 1 6
3 7 11
4 1 7
4 2 4
4 5 5
5 1 4
5 3 4
6 2 8
6 4 10
Output
17
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 1e9;

bool bfs(vector<vector<int>>& capacity, vector<vector<int>>& adj, int s, int t, vector<int>& parent){
    fill(parent.begin(), parent.end(), -1);
    parent[s] = s;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()){
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int v : adj[u]){
            if(parent[v] == -1 && capacity[v][v] > 0){
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if(v == t){
                    return new_flow;
                }
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}

int edmondsKarp(int n, vector<vector<int>>& capacity, vector<vector<int>>& adj, int s, int t){
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow;
    while (new_flow = bfs(capacity, adj, s, t, parent)){
        flow += new_flow;
        int cur = t;
        while (cur != s){
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> capacity(n+1, vector<int>(n+1, 0));
    vector<vector<int>> adj(n+1);

    int s, t;
    cin >> s >> t;

    for(int i = 0; i<m; i++){
        int u, v,c;
        cin >> u >> v >> c;
        capacity[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    cout << edmondsKarp(n, capacity, adj, s, t) << endl;
    return 0;
}

