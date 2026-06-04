class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q;
        map<int, int> mp;
        vector<int> ans;
        
        for (auto& num : nums) {
            auto it = mp.find(num);
            if (it == mp.end()) {
                mp[num] = 1;
            } else {
                mp[num] += 1;
            }
        }

        for (auto& [k, v] : mp) {
            q.push({v, k});
        }

        for (int i = 0; i < k; ++i) {
            auto [count, num] = q.top();
            q.pop();
            ans.push_back(num);
        }

        return ans;
    }
};
