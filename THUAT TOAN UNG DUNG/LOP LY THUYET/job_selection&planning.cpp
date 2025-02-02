/*Description
Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
Select and schedule a subset of jobs of J such that the total profits is maximal.
Input
Line 1: contains a positive integer n (1 <= n <= 10
5
)
Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10
5
)
Output
Write to total profits obtained from the subset of jobs found.

Example
Input
6
3 10
2 40
6 70
3 50
5 80
1 60
Output
300
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

// So sánh để sắp xếp công việc theo lợi nhuận giảm dần
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

int jobScheduling(vector<Job>& jobs, int n) {
    // Sắp xếp các công việc theo lợi nhuận
    sort(jobs.begin(), jobs.end(), compare);

    // Mảng để theo dõi thời gian đã sử dụng
    vector<bool> slot(n, false);
    int totalProfit = 0;

    // Duyệt qua từng công việc đã sắp xếp
    for (int i = 0; i < n; i++) {
        // Tìm một slot trống cho công việc này
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true; // Đánh dấu slot là đã sử dụng
                totalProfit += jobs[i].profit; // Cộng lợi nhuận
                break; // Thoát khỏi vòng lặp
            }
        }
    }

    return totalProfit;
}

int main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);

    // Nhập dữ liệu cho các công việc
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].deadline >> jobs[i].profit;
    }

    // Tính toán và in ra lợi nhuận tối đa
    cout << jobScheduling(jobs, n) << endl;

    return 0;
}
