class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);    // dp[i] stores the length of LIS ending at i
        vector<int> count(n, 1); // count[i] stores the number of LIS ending at i
        int maxLength = 1;       // To track the length of the overall LIS

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // If we find a strictly longer subsequence ending at i
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // Reset count to the count of j
                    } 
                    // If we find another subsequence of the same longest length ending at i
                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j]; // Add the combinations from j
                    }
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        // Sum up the counts for all indices where the LIS length equals the overall maxLength
        int totalNumberOfLIS = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLength) {
                totalNumberOfLIS += count[i];
            }
        }

        return totalNumberOfLIS;
    }
};