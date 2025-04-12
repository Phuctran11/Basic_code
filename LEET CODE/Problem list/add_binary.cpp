/*
Given two binary strings a and b, return their sum as a binary string.


Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            int n1 = a.length();
            int n2 = b.length();
            string result = "";
            int i = n1 -1 ; int j = n2 - 1;
            int q = 0;// to store carry
            while(i >= 0 || j >= 0|| q){
                int sum = q;
                if (i >= 0){
                    sum += a[i] - '0';//convert from string to integer
                    i--;
                }
                if (j >= 0){
                    sum += b[j] - '0';//convert from string to integer
                    j--;
                }
                q = sum / 2;
                result += (sum % 2) + '0';//convert from integer to string
            }
    
            reverse(result.begin(), result.end());
            return result;
            
        }
    };

int main() {
    Solution s;
    string a = "1010";
    string b = "1011";
    cout << s.addBinary(a, b) << endl; // Output: "10101"
    return 0;
}
// Time complexity: O(max(n1, n2)), where n1 and n2 are the lengths of the two binary strings.
// Space complexity: O(max(n1, n2)), for the result string.