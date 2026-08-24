class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= heights.size(); i++) {

            int currentHeight = (i == heights.size())
                ? 0
                : heights[i];

            while (!st.empty() &&
                   heights[st.top()] > currentHeight) {

                int h = heights[st.top()];
                st.pop();

                int leftBoundary = st.empty() ? -1 : st.top();

                int width = i - leftBoundary - 1;

                maxArea = max(maxArea, h * width);
            }

            if (i < heights.size()) {
                st.push(i);
            }
        }

        return maxArea;
    }
};
