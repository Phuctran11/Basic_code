#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX_CUSTOMERS = 12; 
int n, K, Q; 
int demand[MAX_CUSTOMERS + 1]; 
int dist[MAX_CUSTOMERS + 1][MAX_CUSTOMERS + 1]; 
bool visited[MAX_CUSTOMERS + 1]; 
int min_distance = INT_MAX; 

void backtrack(int current_location, int remaining_capacity, int customer_count, int total_distance, int truck_count) {
    if (customer_count == n) { 
        min_distance = min(min_distance, total_distance + dist[current_location][0]); 
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && demand[i] <= remaining_capacity) {
            visited[i] = true;
            backtrack(i, remaining_capacity - demand[i], customer_count + 1, total_distance + dist[current_location][i], truck_count);
            visited[i] = false; 
        }
    }

    
    if (truck_count < K) {
        backtrack(0, Q, customer_count, total_distance + dist[current_location][0], truck_count + 1);
    }
}

void solve() {
    fill(visited, visited + n + 1, false); 
    backtrack(0, Q, 0, 0, 1); 
}

int main() {
    cin >> n >> K >> Q; 
    for (int i = 1; i <= n; ++i) {
        cin >> demand[i]; 
    }
    
   
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cin >> dist[i][j];
        }
    }

    solve(); 
    cout << min_distance << endl; 

    return 0;
}