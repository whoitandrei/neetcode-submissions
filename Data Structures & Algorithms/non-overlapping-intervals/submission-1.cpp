class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });
        
        int count = 1;
        vector<int> cur_interval(intervals[0]);
        int n = intervals.size();
        int i = 1;

        while (i < n) {
            if (cur_interval[1] <= intervals[i][0]) {
                ++count;
                cur_interval = intervals[i];
            }
            ++i;
        }

        return n - count;
    }
};
