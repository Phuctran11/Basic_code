// Description
// Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
// Input
// Line 1: N and M (1≤N,M≤10
// 5
// ) in which NN is the number of nodes and MM is the number of edges.
// Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
// Output
// Write the weight of the minimum spanning tree found.
// Example
// Input
// 5 8
// 1 2 1
// 1 3 4
// 1 5 1
// 2 4 2
// 2 5 1
// 3 4 3
// 3 5 3
// 4 5 2
// Output
// 7

#include <bits/stdc++.h>
using namespace std;

// DSU data structure
// path compression + rank by union
class DSU {
    int* parent;
    int* rank;

public:
    DSU(int n)
    {
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edgelist;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edgelist.push_back({w, u, v});
    }

    // Sort all edges
    sort(edgelist.begin(), edgelist.end());

    // Initialize the DSU
    DSU s(n);
    int ans = 0;
    int count = 0;  // To keep track of the number of edges in MST

    for (auto edge : edgelist) {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        // Take this edge in MST if it does
        // not forms a cycle
        if (s.find(x) != s.find(y)) {
            s.unite(x, y);
            ans += w;
            count++;
        }
        if (count == n - 1) {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
