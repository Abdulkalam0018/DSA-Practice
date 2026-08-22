class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();

        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; i++) {
            int max_val = 0;
            int max_sum = 0;
            for (int j = 1; j <= k && i - j >= 0; j++) {
                max_val = max(max_val, arr[i - j]); 
                max_sum = max(max_sum, dp[i - j] + max_val * j);
            }
            dp[i] = max_sum;
        }
        
        return dp[n];
    }
};