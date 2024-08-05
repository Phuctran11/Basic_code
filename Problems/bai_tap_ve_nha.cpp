#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// Function to compute the total time for each student
vector<long long> compute_total_time(int N, int Q, vector<pair<int, int>>& tasks, vector<int>& student_capabilities) {
    // Sort tasks by their required capability Bi
    sort(tasks.begin(), tasks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    
    // Compute prefix sums of task times
    vector<long long> prefix_sums(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sums[i + 1] = prefix_sums[i] + tasks[i].first;
    }
    
    vector<long long> results(Q);
    
    // Process each student's capability
    for (int i = 0; i < Q; ++i) {
        int capability = student_capabilities[i];
        // Find the rightmost task that the student can handle
        auto it = upper_bound(tasks.begin(), tasks.end(), make_pair(0, capability), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });
        int index = it - tasks.begin();
        // The total time is the prefix sum up to this index
        results[i] = prefix_sums[index];
    }
    
    return results;
}

int main() {
    // Input handling
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<pair<int, int>> tasks(N);
    for (int i = 0; i < N; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }
    
    vector<int> student_capabilities(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> student_capabilities[i];
    }
    
    // Get the results
    vector<long long> results = compute_total_time(N, Q, tasks, student_capabilities);
    
    // Print the results
    for (long long result : results) {
        cout << result << endl;
    }
    
    return 0;
}
