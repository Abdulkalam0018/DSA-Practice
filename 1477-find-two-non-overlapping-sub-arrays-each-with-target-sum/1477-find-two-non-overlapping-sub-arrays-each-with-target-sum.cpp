class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> pref(n, INT_MAX), suff(n, INT_MAX);

        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0, min_len = INT_MAX;
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (mp.count(sum - target)) {
                int len = i - mp[sum - target];
                min_len = min(min_len, len);
            }

            pref[i] = min_len;
            mp[sum] = i;
        }
        unordered_map<int, int> mp2;
        mp2[0] = n;

        sum = 0;
        min_len = INT_MAX;

        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];

            if (mp2.count(sum - target)) {
                int len = mp2[sum - target] - i;
                min_len = min(min_len, len);
            }

            suff[i] = min_len;
            mp2[sum] = i;
        }
        int ans = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            if (pref[i] != INT_MAX && suff[i + 1] != INT_MAX) {
                ans = min(ans, pref[i] + suff[i + 1]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};