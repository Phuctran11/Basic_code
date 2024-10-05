#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_SECONDS = 24 * 3600; 

int timeToSeconds(const string &ftime) {
    int hours = (ftime[0] - '0') * 10 + (ftime[1] - '0');
    int minutes = (ftime[3] - '0') * 10 + (ftime[4] - '0');
    int seconds = (ftime[6] - '0') * 10 + (ftime[7] - '0');
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    string orderID, timePoint;
    vector<int> orderCount(MAX_SECONDS, 0); 

    
    while (true) {
        cin >> orderID;
        if (orderID == "#") break;

        cin >> timePoint;
        int seconds = timeToSeconds(timePoint);
        orderCount[seconds]++;
    }

    
    while (true) {
        string command;
        cin >> command;
        if (command == "###") break;

        if (command == "?number_orders") {
            int totalOrders = 0;
            for (int count : orderCount) {
                totalOrders += count;
            }
            cout << totalOrders << endl;
        } else if (command == "?number_orders_in_period") {
            string fromTime, toTime;
            cin >> fromTime >> toTime;
            int fromSeconds = timeToSeconds(fromTime);
            int toSeconds = timeToSeconds(toTime);
            int count = 0;

            
            for (int i = fromSeconds; i <= toSeconds; ++i) {
                count += orderCount[i];
            }
            cout << count << endl;
        } else if (command == "?number_orders_at_time") {
            string specificTime;
            cin >> specificTime;
            int specificSeconds = timeToSeconds(specificTime);
            cout << orderCount[specificSeconds] << endl;
        }
    }

    return 0;
}
