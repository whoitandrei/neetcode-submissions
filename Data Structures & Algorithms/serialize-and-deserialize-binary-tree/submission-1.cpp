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

#include <cstring>

class Codec {
private:
    void serializer(TreeNode* root, string& s) {
        if (root == nullptr) {
            int val = -1001;
            s.append(reinterpret_cast<const char*>(&val), sizeof(int));
            return;
        }
        s.append(reinterpret_cast<const char*>(&(root->val)), sizeof(int));
        serializer(root->left, s);
        serializer(root->right, s);
    }

    TreeNode* deserializer(const string& s, int& idx) {
        if (idx + sizeof(int) > s.size()) return nullptr;

        int val;
        memcpy(&val, s.data() + idx, sizeof(int));
        idx += sizeof(int);

        if (val == -1001) return nullptr;

        TreeNode* node = new TreeNode(val);

        node->left = deserializer(s, idx);
        node->right = deserializer(s, idx);

        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";  
        serializer(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        int idx = 0;
        return deserializer(data, idx);
    }
};
