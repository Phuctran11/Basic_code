/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

example:
Input: p = [1,2,3], q = [1,2,3]
Output: true
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            //if both roots return true
            if(!p && !q) return true;
            //if each root of value is not same return false
            if(!p || !q || p->val != q->val) return false;
            //in normal case
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };

int main() {
    Solution s;
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    cout << s.isSameTree(p, q) << endl; // Output: 1 (true)
    return 0;
}