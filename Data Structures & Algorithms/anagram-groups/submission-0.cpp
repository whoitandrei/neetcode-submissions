class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        using myarray = array<int, 26>;
        map<myarray, vector<string>> mp;

        for (auto& word : strs) {
            myarray letters = {0};
            for (auto ch : word) {
                letters[ch - 'a'] += 1;
            }

            auto it = mp.find(letters);
            if (it == mp.end()) {
                mp[letters] = { word };
            } else {
                mp[letters].push_back(word);
            }
        }

        vector<vector<string>> ans;
        for (auto& [k, v] : mp) {
            ans.push_back(v);
        }

        return ans;
    }
};
