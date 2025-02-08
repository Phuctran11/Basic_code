/*Description
Given a tree T=(V,E) in which V={1,. . ., n} is the set of nodes. Each edge (u,v) of T has length w(u,v). Denote f(v) the sum of length of paths from all other nodes to v. Write a program to compute max{f(1), .  . ., f(n)}.

Input
Line 1 contains a positive integer n (2 <= n <= 10^5)
Line i+1 (i=1, . . ., n): contains u, v and w in which w is the weight of the edge (u,v)
Output
Write the value max{f(1), . . , f(n}.

Example
Input
4
1 2 1
1 3 3
3 4 2
Output
13
*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN];
vector<int> dpTree(MAXN), subtreeSize(MAXN), result(MAXN);
int n;

// DFS computes dp and subtree sizes for each node
void dfs(int node, int parent) {
    subtreeSize[node] = 1;
    dpTree[node] = 0;

    for (auto &edge : adj[node]) {
        int nebr = edge.first;
        int weight = edge.second;
        if (nebr != parent) {
            dfs(nebr, node);
            subtreeSize[node] += subtreeSize[nebr];
            dpTree[node] += dpTree[nebr] + subtreeSize[nebr] * weight;
        }
    }
}

void reroot(int node, int parent) {
    result[node] = dpTree[node];

    for (auto &edge : adj[node]) {
        int nebr = edge.first;
        int weight = edge.second;
        if (nebr != parent) {
            // Save current states
            int dpNode = dpTree[node];
            int dpNebr = dpTree[nebr];
            int sizeNode = subtreeSize[node];
            int sizeNebr = subtreeSize[nebr];

            // Remove the contribution of nebr from node
            dpTree[node] -= dpTree[nebr] + subtreeSize[nebr] * weight;
            subtreeSize[node] -= subtreeSize[nebr];

            // Add the contribution of node to nebr
            dpTree[nebr] += dpTree[node] + subtreeSize[node] * weight;
            subtreeSize[nebr] += subtreeSize[node];

            reroot(nebr, node);

            // Restore original states
            dpTree[node] = dpNode;
            dpTree[nebr] = dpNebr;
            subtreeSize[node] = sizeNode;
            subtreeSize[nebr] = sizeNebr;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 1; i < n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].emplace_back(v - 1, w);
        adj[v - 1].emplace_back(u - 1, w);
    }

    dfs(0, -1);
    reroot(0, -1);

    long long resultMax = *max_element(result.begin(), result.begin() + n);
    cout << resultMax << endl;

    return 0;
}
