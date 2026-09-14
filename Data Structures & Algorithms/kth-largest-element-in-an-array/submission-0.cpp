class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (auto& num : nums) pq.push(num);

        for (int i = 1; i <= k; ++i) {
            if (i == k) return pq.top();
            pq.pop();
        }
    }
};
