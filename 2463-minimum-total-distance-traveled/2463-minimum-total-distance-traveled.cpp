class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        vector<int> factory_slots;
        for (auto& f : factory) {
            for (int k = 0; k < f[1]; ++k) {
                factory_slots.push_back(f[0]);
            }
        }
        
        int n = robot.size();
        int m = factory_slots.size();
        
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 1e12));
        
        for (int j = 0; j <= m; ++j) {
            dp[0][j] = 0;
        }
        
        // 3. Fill the DP table
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                
                long long skip = dp[i][j - 1];
            
                long long take = dp[i - 1][j - 1] + abs((long long)robot[i - 1] - factory_slots[j - 1]);
                
                dp[i][j] = min(skip, take);
            }
        }
        
        return dp[n][m];
    }
};