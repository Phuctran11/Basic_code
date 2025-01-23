/*Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        return (index != string::npos) ? index : -1;
        // Trong C++, std::string::npos là một hằng số đại diện cho giá trị lớn nhất có thể của kiểu kích thước (size_t) được sử dụng bởi lớp std::string. 
        // Hằng số này thường được sử dụng để chỉ ra rằng một thao tác tìm kiếm không tìm thấy chuỗi con (substring) yêu cầu.
    }
};
 
int main(){
    Solution s;
    cout << s.strStr("sadbutsad", "sad") << endl;
    cout << s.strStr("leetcode", "leeto") << endl;
    return 0;
}