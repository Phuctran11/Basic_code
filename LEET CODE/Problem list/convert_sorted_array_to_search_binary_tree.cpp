/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
*/

#include <iostream>
#include <vector>
#include <functional>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),  left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return buildBST(nums,0, nums.size()-1);
        }
    
    private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right){
        if(left > right) return nullptr;
    
        int mid = left+(right - left)/2;
        TreeNode* node = new TreeNode(nums[mid]);
    
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);
        
        return node;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode* root = s.sortedArrayToBST(nums);
    
    // Function to print the tree in pre-order
    function<void(TreeNode*)> printTree = [&](TreeNode* node) {
        if (node == nullptr) return;
        cout << node->val << " ";
        printTree(node->left);
        printTree(node->right);
    };
    
    printTree(root); // Output: 0 -10 -3 5 9
    return 0;
}