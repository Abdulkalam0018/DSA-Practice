class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (abs(target) > sum || (sum + target) % 2 != 0) return 0;

        int a = (sum + target) / 2;
        vector<int> dp(a + 1, 0);
        dp[0] = 1;
        for (auto &x : nums)
        {
            for (int i = a; i >= x; i--)
            {
                dp[i] += dp[i - x];
            }
        }

        return dp[a];
    }
};