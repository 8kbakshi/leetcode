class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int n = h.size(), ans = 0;

        for(int i = 0; i <= n; i++) {
            int curr = (i == n) ? 0 : h[i];
            while(!st.empty() && curr < h[st.top()]) {
                int height = h[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int r = matrix.size(), c = matrix[0].size();
        vector<int> height(c, 0);
        int ans = 0;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            ans = max(ans, largestRectangleArea(height));
        }
        return ans;
    }
};
