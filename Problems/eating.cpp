#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long A[N];
        int valid[N];
        for (int i = 0; i < N; i++) {
            valid[i] = 0; // not defeated yet
        }

        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        long long hero_power = 1;

        
        int number_defeated = 0; // number of defeated monsters 
        long long min_undefeated = 0;
        while (hero_power >= min_undefeated) {
            for (int i = 0; i < N; i++) {
                if (A[i] <= hero_power && valid[i] == 0) {
                    hero_power += A[i];
                    valid[i] = 1; // defeated
                    number_defeated++;
                }
            }
            // find min monster that is not defeated
            min_undefeated = 1e18; // set to a large value initially
            for (int i = 0; i < N; i++) {
                if (valid[i] == 0) {
                    min_undefeated = min(min_undefeated, A[i]);
                }
            }
        }

        if (number_defeated == N) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }   
       
    }

    return 0;
}
