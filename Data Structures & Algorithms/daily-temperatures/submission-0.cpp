class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<size_t> st;
        vector<int> ans(temperatures.size(), 0);

        for (size_t i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return ans;
    }
};
