// Description
// Given a dataset about orders raised over the time, each item is under the format:
//                                                                                                         <OrderID> <TimePoint>
// in which the order <OrderID> (<OrderID> is a string of length from 2 to 15) is raised at time point <TimePoint> (the <TimePoint> is a string of length 8 representing the time point hh:mm:ss, for example, 08:30:14 means 8 hour 30 minutes 14 seconds)
// Perform a sequence of queries about the given dataset of 3 categories:
// ?number_orders: return the number of orders raised 
// ?number_orders_in_period <FromTimePoint> <ToTimePoint>: return the number of orders raised in the period from time point <FromTimePoint> to time point <ToTimePoint>
// ?number_orders_at_time <TimePoint>: return the number of orders raised at the time point <TimePoint>

// Input
// The first block is a sequence of lines (number of lines can be up to 100000), each line contains an information about an order raised with the format above. The first block is terminated with a line containsing the character #
// The second line is a sequence of lines (number of lines can be up to 100000), each line contains a query described above. The second line is terminated with a line containing ###

// Output
// Write in each line, the result of the correspinding query.

// Example
// Input
// ORD0001 18:48:34
// ORD0002 15:53:51
// ORD0003 08:07:12
// ORD0004 04:06:44
// ORD0005 05:11:40
// ORD0006 00:18:17
// ORD0007 05:09:07
// ORD0008 18:48:34
// ORD0009 02:31:11
// ORD0010 18:48:34
// #
// ?number_orders
// ?number_orders_in_period 03:00:00 06:30:45
// ?number_orders_at_time 18:48:34
// ###

// Output 
// 10
// 3
// 3

#include <iostream>
#include <string>
#include <map>

using namespace std;


int timeToSeconds(const string &ftime) {
    int hours = (ftime[0] - '0') * 10 + (ftime[1] - '0');
    int minutes = (ftime[3] - '0') * 10 + (ftime[4] - '0');
    int seconds = (ftime[6] - '0') * 10 + (ftime[7] - '0');
    return hours * 3600 + minutes * 60 + seconds;
}

int main() {
    string orderID, timePoint;
    map<string, int> orderCount;

    
    while (true) {
        cin >> orderID;
        if (orderID == "#") break; 

        cin >> timePoint; 
        orderCount[timePoint]++;
    }

    
    while (true) {
        string command;
        cin >> command;
        if (command == "###") break;
        if (command == "?number_orders") {
            int totalOrders = 0;
            for (const auto& entry : orderCount) {
                totalOrders += entry.second;
            }
            cout << totalOrders << endl;
        } else if (command == "?number_orders_in_period") {
            string fromTime, toTime;
            cin >> fromTime >> toTime; 
            int count = 0;
            for (const auto& entry : orderCount) {
                if (timeToSeconds(entry.first) >= timeToSeconds(fromTime) &&
                    timeToSeconds(entry.first) <= timeToSeconds(toTime)) {
                    count += entry.second;
                }
            }
            cout << count << endl;
        } else if (command == "?number_orders_at_time") {
            string specificTime;
            cin >> specificTime;
            cout << orderCount[specificTime] << endl; 
        }
    }
    return 0;
}
