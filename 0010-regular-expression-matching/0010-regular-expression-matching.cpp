class Solution {
public:
    int fun(int i, int j, int n, int m, const string& s, const string& p, vector<vector<int>>& dp) {
        if (j == m) return i == n;
        if (dp[i][j] != -1) return dp[i][j];
        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
        int ans = 0;
        if (j < m - 1 && p[j + 1] == '*') {
            ans = fun(i, j + 2, n, m, s, p, dp) || (match && fun(i + 1, j, n, m, s, p, dp));
        } 
        else {
            ans = match && fun(i + 1, j + 1, n, m, s, p, dp);
        }
        
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return fun(0, 0, n, m, s, p, dp);
    }
};