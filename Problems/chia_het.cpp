#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long N;
    cin >> N;

    vector<long long> arr(N);
    long long M = 1;
    for (long long i = 0; i < N; i++) {
        cin >> arr[i];
        M *= arr[i];
    }

    long long T;
    cin >> T;
    
    int result[T];

    for (long long t = 0; t < T; t++) {
        long long X, P;
        cin >> X >> P;

            long long powerOfX = 1;
            for (long long i = 0; i < P; i++) {
                powerOfX *= X;
            }

            if (M % powerOfX == 0 && M >= powerOfX) {
                result[t] = 1;
            } else {
                result[t] = 0; 
            }
    } 
    for (int i = 0; i < T; i++) {
        cout << result[i];
    }

    return 0;
}

