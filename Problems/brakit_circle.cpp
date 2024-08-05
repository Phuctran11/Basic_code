#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else if (c == ')' && !st.empty() && st.top() == '(') {
            st.pop();
        } else {
            return false;
        }
    }
    return st.empty();
}

int main() {
    int N;
    string S;
    cin >> N >> S;

    int count = 0;
    for (std::string::size_type i = 0; i < S.size(); i++) {
        string rotated = S.substr(i) + S.substr(0, i);
        if (isValid(rotated)) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
