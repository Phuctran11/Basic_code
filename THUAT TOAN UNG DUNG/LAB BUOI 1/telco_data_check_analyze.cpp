#include <bits/stdc++.h>
#include <map>

using namespace std;

bool check_phone_number(const string &n) {
    if (n.length() != 10) return false;
    for (char c : n) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int count_time(const string &ftime, const string &etime) {
    int fromtime = 3600 * ((ftime[0] - '0') * 10 + (ftime[1] - '0')) 
                    + 60 * ((ftime[3] - '0') * 10 + (ftime[4] - '0'))
                    + (ftime[6] - '0') * 10 + (ftime[7] - '0');
    
    int endtime = 3600 * ((etime[0] - '0') * 10 + (etime[1] - '0')) 
                    + 60 * ((etime[3] - '0') * 10 + (etime[4] - '0'))
                    + (etime[6] - '0') * 10 + (etime[7] - '0');
    
    return endtime - fromtime;
}

map<string, int> numberCalls, timeCall;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string type;
    int totalCalls = 0;
    int incorrectPhonenumber = 0;

    
    while (true) {
        cin >> type;
        if (type == "#") break;
        totalCalls++;
        string fphone, tphone, date, ftime, etime;
        cin >> fphone >> tphone >> date >> ftime >> etime;
        if (!check_phone_number(fphone) || !check_phone_number(tphone)) incorrectPhonenumber++;
        numberCalls[fphone]++;
        timeCall[fphone] += count_time(ftime, etime);
    }

   
    string command;
    while (true) {
        cin >> command;
        if (command == "#") break;
        if (command == "?check_phone_number") {
            cout << (incorrectPhonenumber == 0 ? '1' : '0') << endl;
        } else if (command == "?number_calls_from") {
            string phonenum;
            cin >> phonenum;
            cout << numberCalls[phonenum] << endl;
        } else if (command == "?number_total_calls") {
            cout << totalCalls << endl;
        } else if (command == "?count_time_calls_from") {
            string phonenum;
            cin >> phonenum;
            cout << timeCall[phonenum] << endl;
        }
    }

    return 0;
}