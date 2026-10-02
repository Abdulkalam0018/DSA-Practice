class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=accumulate(nums.begin(),nums.end(),0LL);

        if((sum+target)%2!=0) return 0;

        int a=(sum+target)/2;
        if(a<0) return 0;
        vector<int>dp(a+1,0);
        dp[0]=1;
        for(auto &x:nums)
        {
            for(int i=a;i>=0;i--)
            {
                if(i-x>=0 && dp[i-x]!=0)
                {
                    dp[i]+=dp[i-x];
                }
            }
        }

        return dp[a];
    }
};