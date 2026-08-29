class WordDictionary {
private:
    struct TreeNode {
        unordered_map<char, TreeNode*> child_;
        bool isEnd_ = false;
    };

    TreeNode* root_;
    
public:
    WordDictionary() : root_(new TreeNode()) {}
    
    void addWord(string word) {
        TreeNode* node = root_;

        for (const auto c : word) {
            if (!node->child_.contains(c)) {
                node->child_[c] = new TreeNode();
            }
            node = node->child_[c];
        }

        node->isEnd_ = true;
    }

    bool dfs(TreeNode* node, int i, const string& word) {
        if (i == word.size()) return node->isEnd_;

        const auto c = word[i];
        if (c != '.') {
            if (!node->child_.contains(c)) {
                return false;
            }
            return dfs(node->child_[c], i + 1, word);
        }

        for (const auto& [k, v] : node->child_) {
            if (dfs(v, i+1, word)) return true;
        }
        return false;
    }
    
    bool search(string word) {
        return dfs(root_, 0, word);
    }
};
