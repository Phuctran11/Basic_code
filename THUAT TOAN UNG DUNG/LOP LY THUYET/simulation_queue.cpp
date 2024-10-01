// Input
// Each line contains a command (operration) of type
// PUSH  v
// POP
// Output
// Write the results of POP operations (each result is written in a line)
// Example
// Input
// PUSH 1
// PUSH 2
// PUSH 3
// POP
// POP
// PUSH 4
// PUSH 5
// POP
// #
// Output
// 1
// 2
// 3

#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    string command;
    queue<int> q;
    while(true){
        
        cin >> command;
        if (command == "#") break;
        if (command == "PUSH"){
            int v;
            cin >> v;
            q.push(v);
        }
        else if (command == "POP"){
            if(!q.empty()){
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << "NULL" << endl;
            }
        }
    }
    return 0;
}