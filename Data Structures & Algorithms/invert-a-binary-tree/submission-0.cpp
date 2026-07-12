/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void revert(TreeNode* root) {
        if (!root) return;
        if (root->left) invertTree(root->left);
        if (root->right) invertTree(root->right);
        
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        revert(root);
        return root;
    }
};
