#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>num_map; //luu tru so va chi so 
        for(int i = 0; i<nums.size(); i++){
            int phan_bu = target - nums[i];
            if(num_map.find(phan_bu) != num_map.end()){//neu phan bu ton tai, tra ve cac chi so
                return {num_map[phan_bu], i};
            }
            num_map[nums[i]] = i; //luu chi so cua so hien tai
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> result = s.twoSum(nums, target);
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}