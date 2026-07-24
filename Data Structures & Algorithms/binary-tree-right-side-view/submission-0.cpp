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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        deque<TreeNode*> level;
        if (!root) return res;
        level.push_back(root);

        while(!level.empty()) {
            int levelSize = level.size();
            
            for (auto i = 0; i < levelSize; ++i) {
                TreeNode* n = level.front();
                level.pop_front();
                if (i == levelSize - 1) {
                    res.push_back(n->val);
                }

                if (n->left) level.push_back(n->left);
                if (n->right) level.push_back(n->right);
            }
        }

        return res;
    }
};
