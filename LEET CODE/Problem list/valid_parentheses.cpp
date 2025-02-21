// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack ; // dùng stack lưu trữ các dấu ngoặc mở

        for (char c : s){ 
            if(c == '(' || c == '{' || c == '[') stack.push(c); // lưu các dấu ngoặc mở
            else {
                if (stack.empty()) return false; // trường hợp có ngoặc đóng mà không có ngoặc mở tương ứng
                char top = stack.top(); // lấy ngoặc mở trên cùng gán vào top
                stack.pop(); //xóa ngoặc đó đi
                if((c == ')') && top != '(' 
                || c == '}' && top != '{'
                || c == ']' && top != '[') return false; // duyệt xem cặp ngoặc đóng và mở có tương ứng không( so sánh c đang xét và top vừa lấy của stack)
            }
        }
        return stack.empty(); // nếu xét hết chuỗi ngoặc và kiểm tra stack đã hết ngoặc mở rồi thì trả về true
    }
};

int main(){
    Solution s;
    string str1 = "([])";
    string str2 = "({[})]";
    cout << s.isValid(str1) << endl;
    cout << s.isValid(str2) << endl;
    return 0;
}