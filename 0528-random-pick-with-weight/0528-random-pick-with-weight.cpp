class Solution {
    vector<int>prefix;
public:
    Solution(vector<int>& w) {
        int cnt=0;
        for(auto &x:w)
        {
            cnt+=x;
            prefix.push_back(cnt);
        }
    }
    
    int pickIndex() {
        int totalsum=prefix.back();
        int a=(rand()%totalsum+1);
        int ans=lower_bound(prefix.begin(),prefix.end(),a)-prefix.begin();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */