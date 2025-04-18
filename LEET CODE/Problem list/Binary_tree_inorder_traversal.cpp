/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.


Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]
*/
#include <iostream>
#include <vector>   

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> result;
            inorderHelper(root, result);
            return result;
        }
    
    private:
        void inorderHelper(TreeNode* node, vector<int>& result){
            if(!node) return;
            inorderHelper(node->left, result);//duyệt cây con bên trái ngoài cùng
            result.push_back(node->val); //lưu giá trị nút hiện tại
            inorderHelper(node->right, result); //duyệt cây con bên phải
        }
    };

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution solution;
    vector<int> result = solution.inorderTraversal(root);

    // Print the result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Clean up memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}