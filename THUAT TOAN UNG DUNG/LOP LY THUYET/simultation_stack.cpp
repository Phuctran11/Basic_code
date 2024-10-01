#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string command;
    stack<int> s;

    while (true){
        cin >> command;
        if ( command == "#") break;
        if (command == "PUSH"){
            int v;
            cin >> v;
            s.push(v);
        } else if (command == "POP"){
            if (!s.empty()){
                cout << s.top() << endl;
                s.pop();
            } else{
                cout << "NULL" << endl;
            }
        }
    }
    return 0;
}