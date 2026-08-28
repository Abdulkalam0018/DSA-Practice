class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int sum=0;
        for(auto &x:nums)
        {
            sum+=x;
            int p=(sum%k+k)%k;
            if(mp.find(p)!=mp.end())
            {
                ans+=mp[p];
            }
            mp[p]++;
        }
        return ans;
    }
};