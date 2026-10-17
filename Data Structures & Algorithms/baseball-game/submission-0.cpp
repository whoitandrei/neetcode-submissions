class Solution {
public:
    int calPoints(vector<string>& operations) {
        deque<int> st;

        for (auto op : operations) {
            if (op == "+") {
                auto f = st[st.size() - 1];
                auto s = st[st.size() - 2];
                st.push_back(s + f);
            } else if (op == "D") {
                st.push_back(st[st.size() - 1] * 2); 
            } else if (op == "C") {
                st.pop_back();
            } else {
                st.push_back(stoi(op));
            }
        }

        int res = 0;
        while (!st.empty()) {
            res += st.front();
            st.pop_front();
        }
        return res;
    }
};