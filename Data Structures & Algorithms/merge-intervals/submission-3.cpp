class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;

        sort(intervals.begin(), intervals.end(), 
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
        });

        res.push_back(intervals[0]);
        int resIdx = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (res[resIdx][1] >= intervals[i][0]) { 
                if (intervals[i][1] > res[resIdx][1]) res[resIdx][1] = intervals[i][1];
            } else {
                res.push_back(intervals[i]);
                resIdx++;
            }
        }

        return res;
    }
};
