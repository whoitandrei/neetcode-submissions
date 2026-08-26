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
    int result = INT_MIN;

    int traverse(TreeNode* root) {
        if (!root) return 0;
        // left
        int left = max(traverse(root->left), 0);
        // right
        int right = max(traverse(root->right), 0);
        // upd result
        result = max(root->val + left + right, result);
        // return result
        return max(left, right) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        traverse(root);
        return result;
    }
};
