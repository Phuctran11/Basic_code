#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    vector<int> new_heights(Q);
    for (int i = 0; i < Q; i++) {
        cin >> new_heights[i];
    }

    for (int i = 0; i < Q; i++) {
        int new_height = new_heights[i];
        N++; // Increase the number of students by 1

        int position = N;
        for (int j = 0; j < N; j++) {
            if (j == N - 1 || new_height < heights[j]) {
                position = j + 1;
                break;
            }
        }

        // Shift students to insert the new student at the correct position
        for (int j = N - 1; j > position - 1; j--) {
            heights[j] = heights[j - 1];
        }
        heights[position - 1] = new_height;

        cout << position << endl;
    }

    return 0;
}
