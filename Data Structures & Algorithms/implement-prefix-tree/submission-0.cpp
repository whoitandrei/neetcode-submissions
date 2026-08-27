struct TreeNode {
    unordered_map<char, TreeNode*> mp_;
    bool isEnd_ = false;
};

class PrefixTree {
private: 
    TreeNode* root_;
public:
    PrefixTree() : root_(new TreeNode()) {}
    
    void insert(string word) {
        TreeNode* cur = root_;
        for (auto c : word) {
            if (!cur->mp_.contains(c)) {
                cur->mp_[c] = new TreeNode();
            }
            cur = cur->mp_[c];
        }
        cur->isEnd_ = true;
    }
    
    bool search(string word) {
        TreeNode* cur = root_;
        for (auto c : word) {
            if (!cur->mp_.contains(c)) return false;
            cur = cur->mp_[c];
        }
        return cur->isEnd_;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root_;
        for (auto c : prefix) {
            if (!cur->mp_.contains(c)) return false;
            cur = cur->mp_[c];
        }
        return true;
    }
};
