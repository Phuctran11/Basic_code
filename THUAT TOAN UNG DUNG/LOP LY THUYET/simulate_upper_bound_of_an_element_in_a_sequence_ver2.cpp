#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    string command;
    while (cin >> command) {
        if (command == "#") break;
        if(command == "next"){
            int k;
            cin >> k;
            auto it = upper_bound(a.begin(), a.end(), k);
            if (it != a.end()) {
                cout << *it << endl;
            } else {
                cout << -1 << endl; 
            }
        }
    }
    return 0;
}