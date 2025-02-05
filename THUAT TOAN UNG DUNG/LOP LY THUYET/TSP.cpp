/*Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. Find the itinerary for that person so that the total travel distance is minimal.
Input
Line 1: a positive integer n (1 <= n <= 20)
Linr i+1 (i = 1, . . ., n): contains the i
th
 row of the distance matrix x (elements are separated by a SPACE character)
Output
Write the total travel distance of the optimal itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

const int MAX_N = 20;
int n;
int distanceMatrix[MAX_N][MAX_N];
int dp[1 << MAX_N][MAX_N]; // dp[mask][i]: chi phí nhỏ nhất đến thành phố i với tập hợp mask các thành phố đã đi qua

int tsp(int mask, int pos) {
    // Nếu đã thăm tất cả các thành phố, quay về thành phố ban đầu
    if (mask == (1 << n) - 1) {
        return distanceMatrix[pos][0];
    }

    // Trả về kết quả đã tính trước đó
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int result = INT_MAX;

    // Duyệt tất cả các thành phố
    for (int city = 0; city < n; city++) {
        // Nếu chưa thăm thành phố này
        if ((mask & (1 << city)) == 0) {
            int newCost = distanceMatrix[pos][city] + tsp(mask | (1 << city), city);
            result = min(result, newCost);
        }
    }

    return dp[mask][pos] = result;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distanceMatrix[i][j];
        }
    }

    // Khởi tạo bảng nhớ dp
    memset(dp, -1, sizeof(dp));

    int result = tsp(1, 0); // Bắt đầu từ thành phố 0 với chỉ thành phố 0 được thăm

    cout << result << endl;

    return 0;
}
