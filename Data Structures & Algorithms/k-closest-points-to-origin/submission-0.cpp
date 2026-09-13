class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using P = vector<int>;

        auto cmp = [](const P& a, const P& b){
            return 1LL*a[0]*a[0] + 1LL*a[1]*a[1]
                    > 1LL*b[0]*b[0] + 1LL*b[1]*b[1];
        };

        std::priority_queue<P, std::vector<P>, decltype(cmp)> pq;

        for (const auto& p : points) pq.push(p);

        vector<P> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};
