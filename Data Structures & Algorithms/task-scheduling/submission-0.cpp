class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        using val_t = std::tuple<int, int>;
        std::priority_queue<val_t, 
                            std::vector<val_t>,
                            std::greater<>> pq;

        std::unordered_map<char, int> freq;
        for (auto& c : tasks) freq[c]++;
        for (auto& [_, f] : freq) pq.push({0, f});

        int time = 0;
        while (!pq.empty()) {
            const auto [t, l] = pq.top();
            if (t > time) time = t;
            if (t <= time) {
                pq.pop();
                if (l > 1) pq.push({ t+n+1, l-1 });
            }
            ++time;
        }

        return time;
    }
};
