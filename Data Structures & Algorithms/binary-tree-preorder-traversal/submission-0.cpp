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
    void traverse(TreeNode* node, vector<int>& state) {
        if (node == nullptr) return;
        state.push_back(node->val);
        traverse(node->left, state);
        traverse(node->right, state);
    }

   public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> st;
        traverse(root, st);
        return st;
    }
};