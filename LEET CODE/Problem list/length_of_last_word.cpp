/*Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int n = s.length();
            int length = 0;
    
            for(int i = n - 1 ; i>= 0; i--){
                if(s[i] == ' '){
                    if(length > 0) break;//khi đếm xong độ dài từ cuối, nếu ktra thấy dấu cách chứng tỏ đã đếm xong độ dài từ cuối cùng, thoát khỏi vòng lặp và trả về kết quả
                }else {
                        length++;
                }
            }
            return length;
        }
    };

int main(){
    Solution s;
    string str = "Anh Bao Phuc dep zai  ";
    cout <<s.lengthOfLastWord(str) << endl;
    return 0;
}