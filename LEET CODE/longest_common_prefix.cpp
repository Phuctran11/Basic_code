// Tìm chuỗi con chung lớn nhất trong danh sách chuỗi đã cho

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        //gia su chuoi chung la chuoi thu nhat
        string prefix = strs[0];
        //kiem tra cac chuoi con lai 
        for(int i = 1; i<strs.size(); i++){
            while (strs[i].find(prefix) != 0){// neu chuoi dang xet khong bat dau bang chuoi prefix
                prefix = prefix.substr(0,prefix.size() - 1); // cat bot 1 ky tu dau cua chuoi prefix
                if(prefix.empty()){ // kiem tra prefix da cat het ky tu chua
                    return ""; // neu prefix da cat het ky tu, chung to khong co chuoi chung
                }
            }
        }
        return prefix;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"flower","flow","flight"};
    cout << "The longest common prefix is: " << s.longestCommonPrefix(strs) << endl;
    return 0;
}