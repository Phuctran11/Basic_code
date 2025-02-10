/*Description
Given a string T and a pattern P which is also a string. Find the number of occurrences of P in T.
Input
Line 1: contains string P (length is less than or equals to 10
5
)
Line 2: contains the string T (length is less than or equals to 10
6
)
Output
Write the number of occurrences of P in T
Example
Input
computer
There are so many kinds of computers today including high performance computers, laptop computers. Mobile phones are also computers
Output
4
*/

#include <iostream>
#include <string>

using namespace std;

int countOccurrences(const string& text, const string& pattern) {
    int count = 0;
    size_t pos = text.find(pattern); // tìm vị trí xuất hiẹn đầu tiên của pattern trong text. Ví dụ pos = 1 nếu "phuc" xuất hiên đầu tiên trong "Chào phuc"

    while (pos != string::npos) {
        /*Câu lệnh này kiểm tra xem vị trí pos có khác với string::npos hay không.
        Nếu pos khác string::npos, điều đó có nghĩa là chuỗi con (pattern) đã được tìm thấy trong chuỗi lớn (text).
        Nếu pos bằng string::npos, điều đó có nghĩa là không còn chuỗi con nào nữa trong chuỗi lớn, và vòng lặp sẽ dừng lại.
        */
        count++; // Increment count for each occurrence
        pos = text.find(pattern, pos + 1); // Find next occurrence
    }

    return count;
}

int main() {
    string pattern, text;

    // Input the pattern and text
    getline(cin, pattern);
    getline(cin, text);

    // Count and output the occurrences
    int occurrences = countOccurrences(text, pattern);
    cout << occurrences << endl;

    return 0;
}
