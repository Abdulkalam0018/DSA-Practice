class Solution {
public:
    int fun(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxk = INT_MIN;
        
        for (int ind = i; ind <= j; ind++) {
            // Calculate coins assuming 'ind' is the LAST balloon burst in the range [i, j]
            int coins = nums[i-1] * nums[ind] * nums[j+1] 
                      + fun(i, ind - 1, nums, dp) 
                      + fun(ind + 1, j, nums, dp);
            
            maxk = max(maxk, coins);
        }
        
        return dp[i][j] = maxk;
    }

    int maxCoins(vector<int>& nums) {
        // Pad array with 1s on both ends
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        // Original balloons are now from index 1 to n-2
        return fun(1, n - 2, nums, dp);
    }
};