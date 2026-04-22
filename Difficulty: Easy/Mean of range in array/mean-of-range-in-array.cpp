class Solution {
  public:
    vector<int> findMean(vector<int> &arr, vector<vector<int>> &queries) {
        int n = arr.size();
        vector<long long> pref(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + arr[i];
        }
        
        vector<int> ans;
        
        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            
            long long sum = pref[r + 1] - pref[l];
            int len = r - l + 1;
            
            ans.push_back(sum / len);  
        }
        
        return ans;
    }
};