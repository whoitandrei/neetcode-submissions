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
    int res;
    int cont = 0;
public:
    void dfs(TreeNode* node,int k){
        if(!node) return;
        dfs(node->left,k);
        cont++;
        if(cont == k) res = node->val;
        dfs(node->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return res;
    }
};
