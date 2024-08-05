#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isprime(int N) {
    if (N <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}

int random_int(int l, int r) {
    return l + rand() % (r - l + 1);
}

int MakeNumber(int S, int K) {
    while (K > 0) {
        int randomNum = random_int(1, 100);
        if (isprime(S) && random_int(1, 10) == 1) {
            K--;
        }
        S += randomNum;
    }
    return S;
}

int main() {
    int S, K, N;
    cin >> S >> K;
    cin >> N;

    int result = MakeNumber(S, K);
    cout << result << endl;

    return 0;
}
