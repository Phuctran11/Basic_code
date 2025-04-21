/*
Given a binary tree, determine if it is height-balanced.
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
*/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isBalanced(TreeNode* root) {
            return checkHeight(root) != -1;   
        }
    
    private:
        int checkHeight(TreeNode* node){
            if( !node ) return 0;
    
            int leftHeight = checkHeight(node->left);
            if(leftHeight == -1) return -1;
    
            int rightHeight = checkHeight(node->right);
            if(rightHeight == -1) return -1;
    
            if(abs(leftHeight - rightHeight) > 1) return -1;
    
            return max(leftHeight, rightHeight) + 1;
    
        }
    };

int main(){
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(4);

    cout << (s.isBalanced(root) ? "true" : "false") << endl; // Output: false

    return 0;
}