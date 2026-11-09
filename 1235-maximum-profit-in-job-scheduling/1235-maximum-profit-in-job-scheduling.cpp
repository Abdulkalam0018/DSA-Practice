class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        using ii = pair<int, pair<int, int>>;
        vector<ii> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {endTime[i], {startTime[i], profit[i]}};
        }
        
        sort(v.begin(), v.end());
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int currentStart = v[i-1].second.first;
            int currentProfit = v[i-1].second.second;
            
            int low = 0, high = i - 1, lastNonConflicting = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (v[mid].first <= currentStart) {
                    lastNonConflicting = mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            dp[i] = max(dp[i-1], currentProfit + dp[lastNonConflicting]);
        }
        
        return dp[n];
    }
};