class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> suffix_min(n);
        
        suffix_min[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_min[i] = min(suffix_min[i + 1], arr[i]);
        }
        
        int ans = 0;
        int prefix_max = 0;
        
        for (int i = 0; i < n - 1; i++) {
            prefix_max = max(prefix_max, arr[i]);
            
            if (prefix_max <= suffix_min[i + 1]) {
                ans++;
            }
        }
        
        return ans + 1;
    }
};