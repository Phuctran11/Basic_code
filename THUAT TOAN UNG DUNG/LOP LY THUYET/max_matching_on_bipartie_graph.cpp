// Description
// There are  n tasks 1,. . .,n and m staffs 1, . . , m. T(i) is the set of staffs that can perform the task i (i=1, . . ., n). Compute an assignment of staffs to tasks such that each task is assigned to at most one staff and each staff cannot be assigned to more than one task and the number of tasks assigned is maximal.
// Input
// Line 1: contains 2 positive integer n và m (1 <=  n,m <= 10000)
// Line i+1 (i=1, . . .,n) contains a positive integer k and k integer of T(i)
// Output
// Write the maximum number of tasks that are assigned to staffs.
// Example
// Input
// 3 4
// 2 1 4
// 2 1 3
// 1 2

// Output
// 3

#include <iostream>
#include <vector>
using namespace std;

bool bpm(vector<vector<int>>& bpGraph, int u, vector<bool>& seen, vector<int>& matchR) {
    // Thử từng công việc một
    for (int v = 0; v < bpGraph[u].size(); v++) {
        int job = bpGraph[u][v];

        // Nếu công việc 'job' chưa được thăm
        if (!seen[job]) {
            // Đánh dấu công việc 'job' là đã được thăm
            seen[job] = true;

            // Nếu công việc 'job' chưa được gán hoặc nhân viên trước đó được gán vào công việc 'job' (matchR[job]) có thể được gán vào công việc khác
            if (matchR[job] < 0 || bpm(bpGraph, matchR[job], seen, matchR)) {
                matchR[job] = u;
                return true;
            }
        }
    }

    return false;
}

int maxBPM(vector<vector<int>>& bpGraph, int n, int m) {
    // Mảng lưu trữ việc gán các nhân viên vào các công việc
    vector<int> matchR(m, -1);

    // Đếm số lượng công việc được gán
    int result = 0;

    for (int u = 0; u < n; u++) {
        // Đánh dấu tất cả các công việc là chưa được thăm
        vector<bool> seen(m, false);

        // Tìm xem liệu có thể gán công việc 'u' cho một nhân viên hay không
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> bpGraph(n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        bpGraph[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> bpGraph[i][j];
            bpGraph[i][j]--;
        }
    }

    cout << maxBPM(bpGraph, n, m) << endl;

    return 0;
}
