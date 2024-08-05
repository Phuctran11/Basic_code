#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countSubarraysWithSumInRange(vector<int>& arr, int i, int j, int L) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;

    for (int k = i; k <= j; k++) {
        sum += arr[k];

        if (sum == L) {
            count++;
        }

        if (prefixSumCount.find(sum - L) != prefixSumCount.end()) {
            count += prefixSumCount[sum - L];
        }

        prefixSumCount[sum]++;
    }

    return count;
}

int main() {
    int N, L, i, j;
    cin >> N >> i >> j >> L;

    vector<int> arr(N);
    for (int k = 0; k < N; k++) {
        cin >> arr[k];
    }

    int result = countSubarraysWithSumInRange(arr, i, j, L);
    cout << result << endl;

    return 0;
}
