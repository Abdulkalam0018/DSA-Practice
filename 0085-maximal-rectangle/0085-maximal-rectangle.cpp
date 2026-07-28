class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> height(m, 0);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            stack<int> st;
            vector<int> h = height;
            h.push_back(0); 
            for (int j = 0; j < h.size(); j++) {
                while (!st.empty() && h[st.top()] > h[j]) {
                    int ht = h[st.top()];
                    st.pop();
                    int wid = st.empty() ? j : (j - st.top() - 1);
                    ans = max(ans, ht * wid);
                }
                st.push(j);
            }
        }
        
        return ans;
    }
};