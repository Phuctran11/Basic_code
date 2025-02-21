//palindrome number is an integer which palindrome when it reads the same forward and backward.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int left = 0;
        int right = str.length() - 1;

        while(left < right){
            if(str[left] != str[right]) return false;
            left ++;
            right --;
        }
        return true;
    }
};

int main(){
    int x = 121;
    int y = 123
    Solution s;
    cout<<s.isPalindrome(x) << endl;
    cout << s.isPalindrome(y) << endl;
    return 0;
}