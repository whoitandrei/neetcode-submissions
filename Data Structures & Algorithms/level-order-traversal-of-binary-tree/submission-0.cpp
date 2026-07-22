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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        deque<TreeNode*> q;
        if (!root) return levels;
        q.push_back(root);
        
        while (!q.empty()) {
            auto levelSize = q.size();
            vector<int> level;
            level.reserve(levelSize);
        
            for (auto i = 0; i < levelSize; ++i) {
                TreeNode* n = q.front();
                level.push_back(n->val);
                q.pop_front();

                if (n->left) q.push_back(n->left);
                if (n->right) q.push_back(n->right);
            }

            levels.push_back(std::move(level));
        }

        return levels;
    }
};
