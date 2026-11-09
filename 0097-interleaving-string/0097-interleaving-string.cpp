class Solution {
public:
    bool fun(int i, int j, int n, int m, string& s1, string& s2, string& s3, vector<vector<int>>& dp)
    {
        int k = i + j; 
        
        if(k == n + m) return true;

        if(dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if(i < n && s1[i] == s3[k]) {
            ans = ans || fun(i + 1, j, n, m, s1, s2, s3, dp);
        }
        
        if(j < m && s2[j] == s3[k]) {
            ans = ans || fun(i, j + 1, n, m, s1, s2, s3, dp);
        }

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        
        if(n + m != s3.size()) return false;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return fun(0, 0, n, m, s1, s2, s3, dp);
    }
};