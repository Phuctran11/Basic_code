#include <iostream>

using namespace std;

int main() {
    int K;
    cin >> K;
    long long arr[K];
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    long long C;
    cin >> C;
    long long X = 1;
    for (int i = 0; i < K; i++) {
        while (C % arr[i] == 0) {
            C /= arr[i];
            X *= arr[i];
        }
    }
    cout << X;
    return 0;
}