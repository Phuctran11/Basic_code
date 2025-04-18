/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
(kiểm tra cây nhị phân có đối xứng hay không)
Example 1:

Input: root = [1,2,2,3,4,4,3]
Output: true
*/

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    public:
        bool isSymmetric(TreeNode* root) {
            if(!root) return true;
            return isMirror(root->left, root->right);
        }
    
    private:
        bool isMirror(TreeNode* r1,TreeNode* r2){
            if(!r1 && !r2) return true;
            if(!r1 || !r2) return false;
            if(r1->val != r2->val) return false;
    
            return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left);
    
        }
    };

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    cout << (s.isSymmetric(root) ? "true" : "false") << endl;

    return 0;
}

