class Solution {
public:
    bool canPartition(vector<int>& nums) {
        using ll=long long;
        ll sum=accumulate(nums.begin(),nums.end(),0LL);

        if(sum%2) return false;

        ll tar=sum/2;

        vector<bool>dp(tar+1,false);
        dp[0]=true;

        for(auto &x:nums)
        {
            for(int i=tar;i>=1;i--)
            {
                if(i-x>=0)
                {
                    dp[i]=dp[i]|dp[i-x];
                }
            }
        }
        return dp[tar];
    }
};