/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.
Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/

#include <iostream>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            if( x < 2) return x;
            int left = 1, right = x/2, mid;
            while (left <= right){
                mid = left + (right - left)/2;
                long long square = (long long) mid*mid;
                if(square == x) return mid;
                else if( square < x) left = mid + 1;
                else right = mid - 1;
            }
            return right;// in case sqrt of 8 is 2,8... so the result rounded down is 2
        }
    };

int main(){
    Solution s;
    cout << s.mySqrt(4) << endl; // Output: 2
    cout << s.mySqrt(8) << endl; // Output: 2
    cout << s.mySqrt(16) << endl; // Output: 4
    cout << s.mySqrt(0) << endl; // Output: 0
    cout << s.mySqrt(1) << endl; // Output: 1
    return 0;
}