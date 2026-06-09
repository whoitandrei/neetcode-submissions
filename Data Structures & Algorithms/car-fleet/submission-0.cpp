class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> data(position.size());
        for (int i = 0; i < position.size(); ++i) {
            data[i] = {position[i], speed[i]};
        }

        sort(data.begin(), data.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        stack<double> st;
        for (auto& [pos, spd] : data) {
            double time = (double)(target - pos) / spd;
            if (st.empty() || time > st.top())
                st.push(time);
        }

        return st.size();
    }
};
