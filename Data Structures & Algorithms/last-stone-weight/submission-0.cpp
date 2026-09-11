class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (auto& stone : stones) {
            pq.push(stone);
        }

        while (pq.size() >= 2) {
            auto first = pq.top(); pq.pop();
            auto second = pq.top(); pq.pop();

            if (first - second > 0) {
                pq.push(first - second);
            }
        }

        if (pq.size() > 0) {
            return pq.top();
        }
        return 0;
    }
};
