//C++ 
#include <iostream> 

using namespace std;

int main() 
{ 
    unsigned long long a,b;
    cin >> a >> b;
    unsigned long long ua, ub, la, lb;
    la = a % 10;
    lb = b % 10;
    ua = a /10;
    ub = b / 10;
    unsigned long long sum_unit, sum_left, carry ;
    sum_left = (la + lb) % 10;
    carry = sum_left / 10;
    sum_unit = ua + ub + carry;
    if ( sum_unit > 0){
        cout << sum_unit;
    }
    cout << sum_left << endl;
    return 0;
    
}

